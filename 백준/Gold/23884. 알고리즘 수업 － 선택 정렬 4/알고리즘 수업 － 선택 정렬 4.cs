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
int K = ReadInt();
int res = 0;
int[] arr = new int[N];
int[] arr2 = new int[N];
Dictionary<int,int> dict = new Dictionary<int,int>();
for (int i = 0; i < N; i++)
{
    arr[i] = ReadInt();
    arr2[i] = arr[i];
    dict.Add(arr[i], i);
}
Array.Sort(arr2);
for (int n = N-1; n > 0; n--)
{
    if (res == K) break;
    if (arr[n] == arr2[n]) continue;
    arr[dict[arr2[n]]] = arr[n];
    dict[arr[n]] = dict[arr2[n]];
    arr[n] = arr2[n];
    res++;
}
if (res < K) Console.WriteLine(-1);
else Console.WriteLine(string.Join(" ", arr));