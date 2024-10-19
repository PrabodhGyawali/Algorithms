import numpy as np
import cv2

MAZE_HEIGHT = 30
MAZE_WIDTH = 30
# Make sure its same with C code
maze = np.zeros(shape=(MAZE_HEIGHT, MAZE_WIDTH))
# Initialize walls: top, right, bottom, left for each cell
walls = [
    [{'top': True, 'right': True, 'bottom': True, 'left': True} for _ in range(MAZE_WIDTH)]
    for _ in range(MAZE_HEIGHT)
]

# Define colors in BGR
COLOR_WALL = (0, 0, 0)        # Black
COLOR_PATH = (255, 255, 255)  # White
COLOR_CURRENT = (0, 255, 0)    # Green
COLOR_VISITED = (0, 0, 255)    # Red

CELL_SIZE = 20

# Create a blank image
img_height = MAZE_HEIGHT * CELL_SIZE
img_width = MAZE_WIDTH * CELL_SIZE
image = np.ones((img_height, img_width, 3), dtype=np.uint8) * 255  # White background

def draw_maze(image, maze, walls):
    for y in range(MAZE_HEIGHT):
        for x in range(MAZE_WIDTH):
            top_left = (x * CELL_SIZE, y * CELL_SIZE)
            bottom_right = ((x + 1) * CELL_SIZE, (y + 1) * CELL_SIZE)
            
            # Determine cell color based on its state
            if maze[y][x] == 0:
                color = COLOR_WALL
            elif maze[y][x] == 1:
                color = COLOR_PATH
            elif maze[y][x] == 2:
                color = COLOR_CURRENT
            elif maze[y][x] == 3:
                color = COLOR_VISITED
            
            # Fill the cell with the determined color
            cv2.rectangle(image, top_left, bottom_right, color, -1)
            
            # Draw walls based on the walls data
            if walls[y][x]['top']:
                cv2.line(image, top_left, (bottom_right[0], top_left[1]), (200, 200, 200), 2)
            if walls[y][x]['right']:
                cv2.line(image, (bottom_right[0], y * CELL_SIZE), (bottom_right[0], bottom_right[1]), (200, 200, 200), 2)
            if walls[y][x]['bottom']:
                cv2.line(image, (x * CELL_SIZE, bottom_right[1]), bottom_right, (200, 200, 200), 2)
            if walls[y][x]['left']:
                cv2.line(image, top_left, (x * CELL_SIZE, bottom_right[1]), (200, 200, 200), 2)
    return image

def remove_wall(walls, current, next_cell):
    y, x = current
    ny, nx = next_cell
    
    if ny == y - 1:  # Next cell is above
        walls[y][x]['top'] = False
        walls[ny][nx]['bottom'] = False
    elif ny == y + 1:  # Next cell is below
        walls[y][x]['bottom'] = False
        walls[ny][nx]['top'] = False
    elif nx == x - 1:  # Next cell is to the left
        walls[y][x]['left'] = False
        walls[ny][nx]['right'] = False
    elif nx == x + 1:  # Next cell is to the right
        walls[y][x]['right'] = False
        walls[ny][nx]['left'] = False

def animate_backtracking(maze, path):
    previous = None
    for position in path:
        y, x = position
        maze[y][x] = 2  # Mark as current path
        
        if previous is not None:
            remove_wall(walls, previous, position)  # Remove wall between previous and current
        previous = position  # Update previous position
        
        # Create a fresh image for the current frame
        image_to_show = np.ones((img_height, img_width, 3), dtype=np.uint8) * 255
        image_to_show = draw_maze(image_to_show, maze, walls)  # Draw maze with updated walls
        
        cv2.imshow('Maze Animation', image_to_show)
        cv2.waitKey(100)  # Wait 100ms
        
        if previous is not None:
            maze[y][x] = 3  # Mark as visited
    
    # Display the final state of the maze
    image_to_show = np.ones((img_height, img_width, 3), dtype=np.uint8) * 255
    image_to_show = draw_maze(image_to_show, maze, walls)
    cv2.imshow('Maze Animation', image_to_show)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

def read_path(file_path):
    path = []
    with open(file_path, 'r') as file:
        for line in file:
            y, x = map(int, line.strip().split(','))
            path.append((y, x))
    return path

# Example backtracking path
path = read_path('output.txt')
animate_backtracking(maze, path)