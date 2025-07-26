/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andcardo <andcardo@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 10:24:44 by andcardo          #+#    #+#             */
/*   Updated: 2025/07/26 11:00:18 by andcardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "get_next_line.h" 

// Function to test a single file
void test_file(const char *filename, const char **expected_lines, int num_expected_lines, const char *test_name) {
    int fd;
    char *line = NULL;
    int line_count = 0;
    int success = 1;

    printf("--- Testing: %s (%s) ---\n", test_name, filename);

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        printf("  [FAIL] Could not open file '%s'.\n", filename);
        printf("--- Test %s FAILED ---\n\n", test_name);
        return;
    }

    // Read and compare lines
    while (1) {
        line = get_next_line(fd);

        if (line == NULL) {
            // End of file reached or error occurred
            break; 
        }

        // Check if we read too many lines
        if (line_count >= num_expected_lines) {
            fprintf(stderr, "  [FAIL] %s: Read line %d, but expected only %d. Content: '%s'\n",
                    test_name, line_count, num_expected_lines, line);
            success = 0;
            free(line); // Free the extra line
            break;
        }

        // Compare the read line with the expected line
        // IMPORTANT: Adjust comparison if your get_next_line strips newlines
        if (strcmp(line, expected_lines[line_count]) != 0) {
            fprintf(stderr, "  [FAIL] %s: Line %d mismatch. Expected: '%s', Got: '%s'\n",
                    test_name, line_count, expected_lines[line_count], line);
            success = 0;
            free(line); // Free the mismatched line
            break;
        }
        
        // printf("  [PASS] Line %d: '%s'", line_count, line); // Uncomment for verbose pass output
        free(line); // Free memory allocated by get_next_line
        line_count++;
    }

    // Final check: Did we read the expected number of lines?
    if (success && line_count != num_expected_lines) {
        fprintf(stderr, "  [FAIL] %s: Expected %d lines, but read %d.\n",
                test_name, num_expected_lines, line_count);
        success = 0;
    }

    close(fd); // Close the file descriptor

    if (success) {
        printf("  [PASS] All %d lines read correctly.\n", num_expected_lines);
        printf("--- Test %s PASSED ---\n\n", test_name);
    } else {
        printf("--- Test %s FAILED ---\n\n", test_name);
    }
}

int main() {

    // --- Test Case: Empty File, No Newline ---
    const char *empty_expected[] = {};
    test_file("tests/empty.txt", empty_expected, 0, "EmptyFile");

    // --- Test Case: Single Line, No Newline ---
    const char *single_no_nl_expected[] = {"This is the only line."};
    test_file("tests/single_no_nl.txt", single_no_nl_expected, 1, "SingleLineNoNL");

    // --- Test Case: Single Line, With Newline ---
    const char *single_nl_expected[] = {"This is a single line.\n"};
    test_file("tests/single_nl.txt", single_nl_expected, 1, "SingleLineWithNL");

    // --- Test Case: Multiple Lines, All With Newlines ---
    const char *multi_nl_expected[] = {
        "First line.\n",
        "Second line.\n",
        "Third line.\n"
    };
    test_file("tests/multi_nl.txt", multi_nl_expected, 3, "MultipleLinesWithNL");

    // --- Test Case: Multiple Lines, Last Line WITHOUT Newline ---
    const char *multi_no_last_nl_expected[] = {
        "Line one.\n",
        "Line two.\n",
        "Last line without newline"
    };
    test_file("tests/multi_no_last_nl.txt", multi_no_last_nl_expected, 3, "MultipleLinesNoLastNL");

    // --- Test Case: File with only newlines ---
    const char *only_newlines_expected[] = {"\n", "\n", "\n"};
    test_file("tests/only_newlines.txt", only_newlines_expected, 3, "OnlyNewlines");

    // --- Test Case: Long File (100 lines) ---
    char **long_file_expected = malloc(100 * sizeof(char *));
    if (!long_file_expected) {
        fprintf(stderr, "Memory allocation failed for long file test!\n");
        return 1;
    }
    char buffer[256]; 
    for (int i = 0; i < 100; ++i) {
        snprintf(buffer, sizeof(buffer), "This is line %d.\n", i + 1);
        long_file_expected[i] = strdup(buffer); 
        if (!long_file_expected[i]) {
            fprintf(stderr, "Memory allocation failed for line %d of long file test!\n", i + 1);
            for (int j = 0; j < i; ++j) free(long_file_expected[j]);
            free(long_file_expected);
            return 1;
        }
    }
    test_file("tests/long_file.txt", (const char **)long_file_expected, 100, "LongFile");

    // --- Cleanup for the long file expected lines ---
    for (int i = 0; i < 100; ++i) {
        free(long_file_expected[i]);
    }
    free(long_file_expected);

    return 0;
}

