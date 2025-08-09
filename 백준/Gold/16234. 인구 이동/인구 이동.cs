using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

byte[] buffer = new byte[1 << 20];
int bufferLength = 0, bufferIndex = 0;

byte ReadByte()
{
    if (bufferIndex == bufferLength)
    {
        bufferLength = Console.OpenStandardInput().Read(buffer, 0, 1 << 20);
        if (bufferLength == 0) return 255;
        bufferIndex = 0;
    }
    return buffer[bufferIndex++];
}
int ReadInt()
{
    int result = 0, sign = 1;
    byte b = ReadByte();
    while (b < '0' || b > '9')
    {
        if (b == '-') sign = -1;
        b = ReadByte();
    }
    while (b >= '0' && b <= '9')
    {
        result = result * 10 + (b - '0');
        b = ReadByte();
    }
    return result * sign;
}
char ReadChar()
{
    byte b = ReadByte();
    while (b <= ' ')
    {
        b = ReadByte();
    }
    return (char)b;
}

int N = ReadInt();
int L = ReadInt();
int R = ReadInt();
int[,] map = new int[N,N];
int[,] visit = new int[N,N];
int res = 0;
int cnt = 0;
int[] dx = new int[4] { -1, 1, 0, 0 };
int[] dy = new int[4] { 0, 0, -1, 1 };

for (int i = 0; i < N; i++)
{
    for (int j = 0; j < N; j++)
    {
        map[i, j] = ReadInt();
    }
}
Queue<Tuple<int, int>> queue = new Queue<Tuple<int, int>>();
Queue<Tuple<int, int>> group = new Queue<Tuple<int, int>>();
while (true)
{
    bool isMove = false;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (visit[i, j] == 1) continue; 
            visit[i, j] = 1;
            queue.Enqueue(new Tuple<int, int>(i, j));
            group.Enqueue(new Tuple<int, int>(i, j));
            cnt += map[i, j];
            if (Move()) isMove = true;
        }
    }
    
    if (!isMove) break;
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            visit[i, j] = 0;
        }
    }
    res++;
}

Console.WriteLine(res);

bool Move()
{
    int x, y;
    
    while (queue.Count > 0)
    {
        (x, y) = queue.Dequeue();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (visit[nx, ny] == 1) continue;
            int abs = Math.Abs(map[nx, ny] - map[x, y]);
            if (abs < L || abs > R) continue;
            visit[nx, ny] = 1;
            queue.Enqueue(new Tuple<int, int>(nx, ny));
            group.Enqueue(new Tuple<int, int>(nx, ny));
            cnt += map[nx, ny];
        }
    }
    int gc = group.Count;

    if (gc == 1)
    {
        group.Clear();
        cnt = 0;
        return false;
    }
    
    while (group.Count > 0)
    {
        (x, y) = group.Dequeue();
        map[x, y] = cnt/gc;
    }

    cnt = 0;
    // PrintMap();
    return true;
}

void PrintMap()
{
    var sb = new StringBuilder();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            sb.Append(map[i, j] + " ");
        }
        sb.AppendLine();
    }
    Console.WriteLine(sb);
}

