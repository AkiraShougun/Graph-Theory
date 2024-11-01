import math


#Perfect square
def is_perfect_square(n):
    return int(math.sqrt(n)) ** 2 == n

def generate_dot_file(filename, vertices):
    with open(filename, 'w') as file:
        file.write("graph G {layout=circo node [shape=circle]; \n")
        for i in range(1, vertices + 1):
            file.write(f"  {i};\n")
        for i in range(1, vertices + 1):
            for j in range(i + 1, vertices + 1):
                if is_perfect_square(i * j):
                    file.write(f"  {i} -- {j};\n")
        file.write("}\n")

if __name__ == "__main__":
    generate_dot_file("perfect.dot", 200)