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
char[,] map = new char[N,N];
bool res = false;
int[] dx = new int[4] { -1, 1, 0, 0 };
int[] dy = new int[4] { 0, 0, -1, 1 };
List<Tuple<int, int>> TList = new List<Tuple<int, int>>();
for (int i = 0; i < N; i++)
{
    for (int j = 0; j < N; j++)
    {
        map[i, j] = ReadChar();
        if (map[i,j] == 'T')
        {
            TList.Add(new Tuple<int, int>(i, j));
        }
    }
}
SetWall(0,0,0);
Console.WriteLine(res ? "YES" : "NO");

void SetWall(int x, int y, int cnt)
{
    if (res) return;
    if (cnt == 3)
    {
        Check();
        return;
    }

    for (int i = x; i < N; i++)
    {
        for (int j = y; j < N; j++)
        {
            if (map[i,j] == 'X')
            {
                map[i, j] = 'O';
                SetWall(i, j+1, cnt + 1);
                map[i, j] = 'X';
            }
        }
        y = 0;
    }
}

void Check()
{
    bool can = true;
    foreach (var xy in TList)
    {
        int x = xy.Item1;
        int y = xy.Item2;
        for (int i = 0; i < 4; i++)
        {
            int nx = x, ny = y;
            while (true)
            {
                nx += dx[i];
                ny += dy[i];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) break;
                if (map[nx,ny] == 'O') break;
                if (map[nx,ny] == 'S')
                {
                    can = false;
                    break;
                }
            }
            if (!can) break;
        }
        if (!can) break;
    }
    res = can;
}