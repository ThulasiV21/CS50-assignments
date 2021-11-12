while True:
    try:
        height = int(Input("Height:"))
        if (height >= 1) or (height <= 8):
            break
        else:
            print("", end="")
spaces = 1
for j in range(height):
    for spaces in range(height-j-1):
        print(" ", end="")
    for i in range(j+1)
        print("#", end="")
    print()

#if __name__ == "__main__":
 #   main()

