# Maze Game
This is a c program I wrote for a my Coursework in my Programming Project module for the University of Leeds.

To run the maze game:
Run `$ make` to compile the c files and link them into a binary file called `maze`.
Now run pass 1 argument variable with a path of a .txt file representing a maze.
`$ maze <path-to-maze-file>` eg: `$ maze ../maze.txt`

Run `$ make clean` to clean directory from binary files.

- I have decided to add an extension to this project by trying to use the a* algorithm to traverse through this maze. 
- In order to achieve this goal I have to create a maze-generating algorithm to implement this a* algorithm on.

# Issues to fix:
- Doesn't work when I create my own maze file in the text editor:
    - `maze.txt` has some problems due to some unknown character at the end of the first line when created from the text-editor.

