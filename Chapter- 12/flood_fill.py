M = 8
N = 8

def flood_Fill_until(screen, x, y, old_Color, new_Color):
    
    if (x < 0 or x >= M or y < 0 or
            y >= N or screen[x][y] != old_Color or
            screen[x][y] == new_Color):
        return

    screen[x][y] = new_Color

    flood_Fill_untill(screen, x + 1, y, old_Color, new_Color)
    flood_Fill_untill(screen, x - 1, y, old_Color, new_Color)
    flood_Fill_untill(screen, x, y + 1, old_Color, new_Color)
    flood_Fill_untill(screen, x, y - 1, old_Color, new_Color)


def flood_Fill(screen, x, y, new_Color):
    old_Color = screen[x][y]
    if (old_Color == new_Color):
        return
    flood_Fill_untill(screen, x, y, old_Color, new_Color)

screen = [[1, 1, 1, 1, 1, 1, 1, 1],
          [1, 1, 1, 1, 1, 1, 0, 0],
          [1, 0, 0, 1, 1, 0, 1, 1],
          [1, 2, 2, 2, 2, 0, 1, 0],
          [1, 1, 1, 2, 2, 0, 1, 0],
          [1, 1, 1, 2, 2, 2, 2, 0],
          [1, 1, 1, 1, 1, 2, 1, 1],
          [1, 1, 1, 1, 1, 2, 2, 1]]

x = 5
y = 5
new_Color = 2
flood_Fill(screen, x, y, new_Color)

print("Updated screen after call to Flood Fill :")
for i in range(M):
    for j in range(N):
        print(screen[i][j], end=' ')
    print()