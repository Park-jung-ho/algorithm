using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

byte[] buffer = new byte[1 << 20];
int bufferLength = 0, bufferIndex = 0;

int N = ReadInt();
int K = ReadInt();
int[,] map = new int[N, N];
int res = 0;
int[] dx = new int[4] { -1, 1, 0, 0 };
int[] dy = new int[4] { 0, 0, -1, 1 };
for (int i = 0; i < N; i++)
{
    for (int j = 0; j < N; j++)
    {
        map[i, j] = ReadInt();
    }
}
int S = ReadInt();
int X = ReadInt() - 1;
int Y = ReadInt() - 1;
List<Queue<Tuple<int,int>>> queue = new List<Queue<Tuple<int,int>>>();
for (int i = 0; i <= K; i++)
{
    queue.Add(new Queue<Tuple<int,int>>());
}
for (int i = 0; i < N; i++)
{
    for (int j = 0; j < N; j++)
    {
        if (map[i, j] != 0)
        {
            queue[map[i, j]].Enqueue(new Tuple<int,int>(i, j));
        }
    }
}

while (S > 0)
{
    S--;
    for (int i = 1; i <= K; i++)
    {
        int cnt = queue[i].Count;
        while (cnt > 0)
        {
            cnt--;
            int x, y;
            (x, y) = queue[i].Dequeue();
            for (int j = 0; j < 4; j++)
            {
                int nx = x + dx[j];
                int ny = y + dy[j];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if (map[nx, ny] != 0) continue;
                map[nx, ny] = i;
                queue[i].Enqueue(new Tuple<int,int>(nx, ny));
            }
        }
    }
}

res = map[X, Y];
Console.WriteLine(res);

byte ReadByte()
{
    if (bufferIndex == bufferLength)
    {
        bufferLength = Console.OpenStandardInput().Read(buffer, 0, 1 << 20);
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