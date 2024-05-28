# File Compression and Decompression
**This C++ program implements Run-Length Encoding (RLE) and Run-Length Decoding (RLD) algorithms. It reads input from a file, performs either encoding or decoding based on user choice, and writes the result to an output file. RLE compresses consecutive repeated characters by representing them as character-count pairs, while RLD decompresses the encoded text back to its original form.** 
## Instruction 
**Initialization**
The program opens an input file stream to read from the file "input.txt" and an output file stream to write to "output.txt".

**User Input:**
The user is prompted to choose between encoding (E) and decoding (D).

**Encoding (E):**
If the user selects encoding:
Each line of text from the input file is read.
The program applies Run-Length Encoding (RLE) to the text, compressing consecutive repeated characters.
The compressed text is written to the output file.

**Decoding (D):**
If the user selects decoding:
Each line of text from the input file is read.
The program applies Run-Length Decoding (RLD) to the text, decompressing the encoded text back to its original form.
The decompressed text is written to the output file.

**File Closure:**
After processing all lines, the input and output file streams are closed.
That's it! The program provides a simple interface for performing Run-Length Encoding and Decoding operations on text files.






