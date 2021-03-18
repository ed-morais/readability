# readability
A program that computes the approximate grade level needed to comprehend some text, a project from the Harvard's CS50x course (2020), entirely written in C.

The program is based on the Coleman-Liau index, which is designed to output what (U.S.) grade level is needed to understand the text.

If the resulting index number is 16 or higher (equivalent to or greater than a senior undergraduate reading level), the program should output "Grade 16+" instead of giving the exact index number. If the index number is less than 1, the program should output "Before Grade 1".

The formula is:
index = 0.0588 * L - 0.296 * S - 15.8
Here, L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.

Usage:

  $ ./readability
  Text: Congratulations! Today is your day. You're off to Great Places! You're off and away!
  Grade 3

