# 🧊 cub3d
Ray-casting / mini Wolfenstein 3D

# Useful resources

1. [raycasting](https:mediumcom@rtailidouniaraycasting-in-cub3d-42-network-project-a-practical-tutorial-using-vectors-68eeb16b3de2)
2. [reactive](https://reactive.so/post/42-a-comprehensive-guide-to-cub3d/)
3. [raycasting youtube](https://www.youtube.com/watch?v=gYRrGTC7GtA&list=PLCWsH9Tj9oWyDM4W43VMj5yo2PdyYMGst)

# Układ struktur

data -> główna struktura przetrzymująca wszystkie inne struktury, służy do przekazywania struktur pomiędzy funkcjami<br>
mlx -> do zarządzania oknem<br>
map -> wszystkie zmienne dotyczące i potrzebne do działania mapy<br>
player -> wszystkie zmienne potrzebne do obsługi mechaniki gracza<br>

każda ze struktur ma odniesienie do data na wszelki wypadek, przez co łatwo dostać się do innych zmiennych
