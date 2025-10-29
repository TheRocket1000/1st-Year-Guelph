/*
 * printf_scanf_playground.c
 * ------------------------------------------------------------
 * A single, self‑contained C program focused ONLY on console input/output
 * using printf and scanf. It is intentionally long and richly commented so
 * students can explore VS Code editing features (multicursor, rename
 * symbol, moving lines, block selection, split view, breadcrumbs, outline,
 * search/replace, folding, and code formatting). 
 *
 * Build:
 *   gcc printf_scanf_playground.c -Wall -Wextra -Wpedantic -std=c17 -o io_playground.exe 
 * Run:
 *   ./io_playground.exe
 *
 * Constraints:
 * - Uses ONLY stdio (printf/scanf). No fgets/gets/sscanf, no strings.h, etc.
 * - Exercises emphasize format specifiers, width/precision, flags, scanning
 *   patterns, whitespace handling, scansets, and error checking via scanf's
 *   return value that indicates how many fields were successfully read.
 *
 * TA notes / student tasks (use these to practice VS Code features):
 *  1) Search (Ctrl/Cmd+F) for "TODO" and complete tasks.
 *  2) Practice multicursor: highlight repeated variable names (e.g., demoVar)
 *     and edit them everywhere.
 *  3) Try moving entire blocks (Alt+Up/Down on Windows/Linux, Option+Up/Down
 *     on macOS) to reorder demos.
 *  4) Fold/unfold regions marked with // ======= to navigate quickly.
 *  5) Open the Outline view and jump between demo_* functions.
 *  6) Split editor (Right‑click tab → Split) and view two locations at once.
 *  7) Practice selection: Alt/Option + drag for column selection. 
 *  8) Use format on save (enable in VS Code) and notice alignment.
 *  9) Rename symbols (F2) on functions like demo_integers to see safe renames.
 * 10) Use Run/Debug CodeLens or create a simple launch.json if desired.
 *
 * Input tips:
 * - When scanf blocks, it is waiting for input. Provide what the prompt asks.
 * - Whitespace in format strings often matters (e.g., " %c" skips newlines).
 * - DO NOT paste huge multi‑line inputs at once until you read the prompt.
 */



/**
 * Author: Pratham Lonial
 * Username: plonial
 * ID: 1369004
 */
#include <stdio.h>

// Forward declarations for menu demos
void demo_integers(void);
void demo_floats(void);
void demo_width_precision(void);
void demo_width_precisionb(void);
void demo_flags_signs(void);
void demo_chars_and_strings(void);
void demo_scanf_basics(void);
void demo_scanf_whitespace(void);
void demo_scanset_basic(void);
void demo_scanset_negated(void);
void demo_mixed_io(void);
void demo_bases_output(void);
void demo_percent_n(void);
void demo_error_handling(void);
void demo_alignment_table(void);
void demo_literal_percent(void);
void demo_pointer_output(void);
void demo_time_input(void);

// Utility used in a few demos: pause until ENTER (still only stdio)
static void wait_enter(void) {
    int ch;
    printf("\nPress ENTER to continue...\n");
    // Consume until newline (works even if leftover input exists)
    while ((ch = getchar()) != '\n' && ch != EOF) { /* discard */ }
}

static void print_menu(void) {
    puts("\n================= printf/scanf Playground =================");
    puts(" 1) Integers (printf & scanf basics)");
    puts(" 2) Floating‑point (printf & scanf basics)");
    puts(" 3) Width & precision (printf)");
    puts(" 4) Flags & signs (printf)");
    puts(" 5) Chars & strings (printf & scanf)");
    puts(" 6) scanf return values & basics");
    puts(" 7) scanf and whitespace control");
    puts(" 8) Scanset: %[abc...] basics");
    puts(" 9) Scanset: negated %[^...] ");
    puts("10) Mixed I/O: reading multiple fields");
    puts("11) Bases output: %d %i %u %o %x %X");
    puts("12) The mysterious %%n (count of printed chars)");
    puts("13) Error handling with scanf (robust input loop)");
    puts("14) Alignment table (printf formatting practice)");
    puts("15) Printing a literal percent sign (%%)");
    puts("16) Pointer output with %p (addresses)");
    puts("17) Width and Precision variations [TODO A]");
    puts("18) Time input with scanf (HH:MM:SS) [TODO B]");
    puts(" 0) Quit");
    puts("==========================================================");
}

int main(void) {
    for (;;) {
        int choice = -1;
        print_menu();
        printf("Enter a choice (0-18): ");
        if (scanf("%d", &choice) != 1) {
            // Invalid entry; clear input and continue
            int c;
            puts("\nInvalid choice. Please enter a number.");
            while ((c = getchar()) != '\n' && c != EOF) {}
            continue;
        }

        // Consume the trailing newline so subsequent demos that read lines work
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}

        switch (choice) {
            case 1:  demo_integers(); break;
            case 2:  demo_floats(); break;
            case 3:  demo_width_precision(); break;
            case 4:  demo_flags_signs(); break;
            case 5:  demo_chars_and_strings(); break;
            case 6:  demo_scanf_basics(); break;
            case 7:  demo_scanf_whitespace(); break;
            case 8:  demo_scanset_basic(); break;
            case 9:  demo_scanset_negated(); break;
            case 10: demo_mixed_io(); break;
            case 11: demo_bases_output(); break;
            case 12: demo_percent_n(); break;
            case 13: demo_error_handling(); break;
            case 14: demo_alignment_table(); break;
            case 15: demo_literal_percent(); break;
            case 16: demo_pointer_output(); break;
            case 17: demo_width_precisionb(); break;
            case 18: demo_time_input(); break;
            case 0:  puts("Goodbye!"); return 0;
            default: puts("Unknown choice. Try again."); break;
        }
    }
}

// ======= Demo 1: Integers ==================================================
void demo_integers(void) {
    puts("\n[Demo 1] Integers with printf/scanf\n----------------------------------");
    int a = 0, b = 0;
    printf("Enter two integers separated by space: ");
    if (scanf("%d %d", &a, &b) != 2) {
        puts("Input error: expected two integers.");
    } else {
        printf("You entered a=%d and b=%d\n", a, b);
        printf("Sum: %d, Product: %d, Difference: %d\n", a + b, a * b, a - b);
    }
    wait_enter();
}

// ======= Demo 2: Floats ====================================================
void demo_floats(void) {
    puts("\n[Demo 2] Floating‑point with printf/scanf\n----------------------------------------");
    double x = 0.0, y = 0.0;
    printf("Enter two floating numbers (e.g., 3.14 2.5): ");
    if (scanf("%lf %lf", &x, &y) != 2) {
        puts("Input error: expected two doubles.");
    } else {
        printf("x=%.6f, y=%.6f\n", x, y);
        printf("x+y=%.6f, x*y=%.6f, x/y=%.6f\n", x + y, x * y, (y != 0.0 ? x / y : 0.0));
        printf("Scientific: x=%e, y=%E\n", x, y);
        printf("Shortest (%%g): x=%g, y=%g\n", x, y);
    }
    wait_enter();
}

// ======= Demo 3: Width & precision (printf) ================================
void demo_width_precision(void) {
    puts("\n[Demo 3] Width & precision (printf)\n-----------------------------------");
    double v = 123.456789;
    printf("Default:         %f\n", v);
    printf("Precision .2:    %.2f\n", v);
    printf("Precision .5:    %.5f\n", v);
    printf("Width 12:        %12f\n", v);
    printf("Width 12,.2:     %12.2f\n", v);
    printf("Left‑align:      %-12.2f(\n)", v);
    printf("Zero‑pad:        %012.2f\n", v);
    printf("Integers width:  |%5d| |%5d| |%5d|\n", 3, 33, 333);
    printf("Left align ints: |%-5d| |%-5d| |%-5d|\n", 3, 33, 333);
    wait_enter();
}

void demo_width_precisionb(void) {
    puts("\n[Demo 3b] Width & precision (printf)\n-----------------------------------");
    double v = 123.456789;
    printf("Default:         %f\n", v);
    printf("Precision .2:    %.2f\n", v);
    printf("Precision .5:    %.5f\n", v);
    printf("Width 12:        %8f\n", v);
    printf("Width 12,.2:     %8.3f\n", v);
    printf("Left‑align:      %-8.3f(\n)", v);
    printf("Zero‑pad:        %0.3f\n", v);
    printf("Integers width:  |%5d| |%5d| |%5d|\n", 3, 33, 333);
    printf("Left align ints: |%-5d| |%-5d| |%-5d|\n", 3, 33, 333);
    wait_enter();
}

// ======= Demo 4: Flags & signs (printf) ====================================
void demo_flags_signs(void) {
    puts("\n[Demo 4] Flags & signs (printf)\n------------------------------");
    int p = 42, n = -42, z = 0;
    printf("Default: p=%d n=%d z=%d\n", p, n, z);
    printf("Always show sign (%%+d): %+d %+d %+d\n", p, n, z);
    printf("Space for positive (%% d): % d % d % d\n", p, n, z);
    printf("Zero‑pad width 6 (%%06d): %06d %06d %06d\n", p, n, z);
    printf("Alternate form hex/oct (%%#x %%#o): %#x %#o\n", 255, 255);
    wait_enter();
}

// ======= Demo 5: Chars & strings ===========================================
void demo_chars_and_strings(void) {
    puts("\n[Demo 5] Characters & Strings with printf/scanf\n-----------------------------------------------");
    char c1 = '\0', c2 = '\0';
    char word[64];

    printf("Enter two characters (note: first will skip whitespace): ");
    if (scanf(" %c%c", &c1, &c2) == 2) {
        printf("You typed c1='%c' and c2='%c' (codes %d, %d)\n", c1, c2, (int)c1, (int)c2);
    } else {
        puts("Failed to read two chars.");
    }

    printf("Enter a single word (no spaces): ");
    if (scanf("%63s", word) == 1) {
        printf("Word: %s\n", word);
        printf("As quoted: '%s'\n", word);
    } else {
        puts("Failed to read a word.");
    }
    char shortWord[11]; //10 chars + null terminator
    printf("Enter a word (max 10 chars): ");
    if(scanf("%10s", shortWord) == 1){
        printf("Fixed-width column: |%12s|\n", shortWord);
    }
    else{
        puts("Failed to read a short word.");
    }

    wait_enter();
}

// ======= Demo 6: scanf return values & basics ===============================
void demo_scanf_basics(void) {
    puts("\n[Demo 6] scanf return values\n----------------------------");
    int a; double b; char w[16];
    printf("Enter: <word> <int> <double>\nExample: hello 10 3.14\n> ");
    int rc = scanf("%15s %d %lf", w, &a, &b);
    printf("scanf returned %d\n", rc);
    if (rc == 3) {
        printf("Parsed: w=%s a=%d b=%.3f\n", w, a, b);
    } else {
        puts("Parsing failed — check your input order and types.");
    }
    wait_enter();
}

// ======= Demo 7: scanf & whitespace ========================================
void demo_scanf_whitespace(void) {
    puts("\n[Demo 7] scanf & whitespace\n--------------------------");
    char cA='?', cB='?';
    printf("Type two characters separated by ENTER. First format is '%%c %%c' (no skip).\n");
    printf("Input now: ");
    if (scanf("%c %c", &cA, &cB) == 2) {
        printf("Read with '%%c %%c': cA='%c' cB='%c'\n", cA, cB);
    } else {
        puts("Failed first read.");
    }
    int ch; while ((ch = getchar()) != '\n' && ch != EOF) {}

    printf("Now using ' %%c %%c' (leading space). Type two characters again: ");
    if (scanf(" %c %c", &cA, &cB) == 2) {
        printf("Read with ' %%c %%c': cA='%c' cB='%c'\n", cA, cB);
    } else {
        puts("Failed second read.");
    }
    wait_enter();
}

// ======= Demo 8: Scanset basic %[... ] =====================================
void demo_scanset_basic(void) {
    puts("\n[Demo 8] Scanset basics with %%[abc...]\n--------------------------------------");
    char buf[64];
    printf("Enter letters a, b, or c only (stop when other char seen): ");
    if (scanf("%63[abc]", buf) == 1) {
        printf("Scanset captured: '%s'\n", buf);
    } else {
        puts("No a/b/c letters read (first char wasn't in the set).");
    }
    // Clear rest of line
    int ch; while ((ch = getchar()) != '\n' && ch != EOF) {}
    wait_enter();
}

// ======= Demo 9: Scanset negated %[^...] ===================================
void demo_scanset_negated(void) {
    puts("\n[Demo 9] Negated scanset with %%[^...]\n-------------------------------------");
    char buf[64];
    printf("Type characters until you hit a digit (0‑9) — digits END the scan: ");
    if (scanf("%63[^0-9]", buf) == 1) {
        printf("Captured non‑digits: '%s'\n", buf);
    } else {
        puts("First character was a digit; captured nothing.");
    }
    int ch; while ((ch = getchar()) != '\n' && ch != EOF) {}
    wait_enter();
}

// ======= Demo 10: Mixed I/O =================================================
void demo_mixed_io(void) {
    puts("\n[Demo 10] Mixed fields\n----------------------");
    int id; double score; char grade; char name[32]; int hex;
    printf("Enter: <id:int> <score:double> <grade:char> <name:word> <hex:int>\n");
    printf("Example: 123 87.5 A Alice 0A1B\n> ");
    int rc = scanf("%d %lf %c %31s %x", &id, &score, &grade, name, &hex);
    if (rc == 5) {
        printf("id=%d score=%.2f grade=%c name=%s hex=%d, %#x\n", id, score, grade, name, hex, hex);
    } else {
        printf("Parsed %d/5 fields. Check spacing and types.\n", rc);
    }
    wait_enter();
}

// ======= Demo 11: Bases output =============================================
void demo_bases_output(void) {
    puts("\n[Demo 11] Integer bases output\n------------------------------");
    unsigned int u;
    printf("Enter a non‑negative integer: ");
    if (scanf("%u", &u) == 1) {
        printf("decimal (%%u): %u\n", u);
        printf("octal   (%%o): %o\n", u);
        printf("hex low (%%x): %x\n", u);
        printf("hex up  (%%X): %X\n", u);
        printf("with # flag:  %#o  %#x  %#X\n", u, u, u);
    } else {
        puts("Not an unsigned integer.");
    }
    wait_enter();
}

// ======= Demo 12: %%n (count) ===============================================
void demo_percent_n(void) {
    puts("\n[Demo 12] The %%n specifier (count chars printed so far)\n-------------------------------------------------------");
    int count = 0;
    printf("Hello, counting... ");
    printf("12345");
    printf("%n", &count); // stores the number of characters printed so far into count
    printf(" (stored count=%d)\n", count);
    // NOTE: %%n is output‑only side effect, not commonly used; know it exists.
    wait_enter();
}

// ======= Demo 13: Error handling with scanf ================================
void demo_error_handling(void) {
    puts("\n[Demo 13] Robust input loop with scanf return check\n---------------------------------------------------");
    int value;
    for (int i = 0; i < 3; ++i) {
        printf("Attempt %d — enter an integer: ", i + 1);
        int rc = scanf("%d", &value);
        if (rc == 1) {
            printf("Thanks! You typed %d\n", value);
        } else if (rc == EOF) {
            puts("EOF encountered — stopping.");
            break;
        } else {
            puts("That wasn't an integer. Clearing input...");
        }
        int ch; while ((ch = getchar()) != '\n' && ch != EOF) {} // clear line
    }
    wait_enter();
}

// ======= Demo 14: Alignment table ==========================================
void demo_alignment_table(void) {
    puts("\n[Demo 14] Alignment practice table (printf)\n-------------------------------------------");
    puts("Try adjusting widths/precisions and observe alignment.");
    puts("Use multicursor to edit many format strings at once.\n");

    const char *label1 = "Alpha";
    const char *label2 = "Beta";
    const char *label3 = "GammaLong";

    int a = 7, b = 123, c = -42;
    double x = 3.14159, y = 2.71828, z = -0.00012;

    puts("Before adjustments:");
    printf("|%10s|%10s|%10s|\n", "Label", "Int", "Float");
    printf("|%10s|%10d|%10.3f|\n", label1, a, x);
    printf("|%10s|%10d|%10.3f|\n", label2, b, y);
    printf("|%10s|%10d|%10.3f|\n", label3, c, z);

    puts("\nLeft aligned with signs, zero‑pad ints, fixed floats:");
    printf("|%-10s|%+010d|%12.6f|\n", label1, a, x);
    printf("|%-10s|%+010d|%12.6f|\n", label2, b, y);
    printf("|%-10s|%+010d|%12.6f|\n", label3, c, z);

    wait_enter();
}

// ======= Demo 15: Literal percent ==========================================
void demo_literal_percent(void) {
    puts("\n[Demo 15] Printing a literal percent sign (%%)\n---------------------------------------------");
    double progress = 73.5;
    printf("Progress: %.1f%% complete\n", progress);
    wait_enter();
}

// ======= Demo 16: Pointer output ===========================================
void demo_pointer_output(void) {
    puts("\n[Demo 16] Pointer output with %p (addresses)\n--------------------------------------------");
    int local = 123;
    int *ptr = &local;
    printf("Address of local (&local): %p\n", (void*)&local);
    printf("Value of ptr:               %p\n", (void*)ptr);
    printf("Dereferenced *ptr (printf %%d): %d\n", *ptr);
    puts("Note: %p uses an implementation‑defined format; cast to (void*) is common.");
    wait_enter();
}

// Demo 17
void demo_time_input(void) {
    puts("\n[Demo 17] Time input and formatted output\n--------------------------------------------");
    int hours, minutes, seconds;
    printf("Enter time as HH:MM:SS (eg- 09:30:05): ");
    if (scanf("%d:%d:%d", &hours, &minutes, &seconds) == 3) {
        printf("You entered: %02d:%02d:%02d\n", hours, minutes, seconds);
    } else {
        puts("Invalid format. Please use HH:MM:SS.");
    }
    wait_enter();
}

/* =========================== Extended TODOs ===============================
 *
 * Use these guided edits to practice VS Code features without changing the
 * program’s focus (printf/scanf only):
 *
 * TODO A) Duplicate Demo 3 block and create a Demo 3b that experiments with
 *        different widths (e.g., %8.3f, %-8.3f, %08.3f). Add it to the menu.
 *
 * TODO B) In Demo 5, add another scanf that limits string length to 10 chars
 *        ("%10s") and print it in a fixed‑width column of 12 characters.
 *
 * TODO C) In Demo 6, change the order of fields to <word> <int> <double> and
 *        update both the prompt and the format string accordingly.
 *
 * TODO D) In Demo 10, add one more field: a hex integer (use "%x") and print
 *        it back as decimal and hex with %#x.
 *
 * TODO E) Create a new demo that reads a time as HH:MM:SS using scanf("%d:%d:%d")
 *        and then prints it with zero‑padded fields (e.g., %02d:%02d:%02d).
 *        Add it to the menu.
 *
 * TIP: Try multicursor to change all "wait_enter" calls to another helper name
 *      (rename function with F2 first, then references update automatically).
 *
 * ========================================================================== */
