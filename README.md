**BY `Bachir Bouadjera Mohamed Elmokhtar` AND`Chouaki Walid`**

Lexical tokenization is conversion of a text into meaningful lexical tokens belonging to categories defined by our program.
This project is intended for learning and demonstration purposes, showing how a hand-written lexer works without external libraries.
## cleaner.c
- Mimics the **preprocessing step** of a compiler.
- Cleans and removes **comments** and **include headers** from `code.c`, producing a clean file `clean.c` that contains only the function definitions.
## tokenization.c
- this code do the tokenization process , it reads the whole `clean.c` file and divides it into :
	- operators (e.g., `+`, `-`, `==`, `!=`)
	- separators (e.g., `;`, `{`, `}`, `(`, `)`)
	- keywords (e.g., `int`, `if`, `return`)
	- identifiers (variable and function names)
	- literals :
		- String literals (`"example"`)
		- Character literals (`'a'`)
		- Number literals (integer and floating-point)
- the code also counts the number of each token 
- the code is structured and well commented on each token detection
- The code outputs the detected tokens and counts into `token.txt`
- It uses a simple character-by-character scanning approach and handles basic multi-character operators.

