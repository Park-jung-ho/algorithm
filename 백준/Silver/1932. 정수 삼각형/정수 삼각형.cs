using System;
using System.Collections.Generic;

List<List<int>> list = new List<List<int>>();
int res = 0;
int n = int.Parse(Console.ReadLine());
for (int i = 0; i < n; i++)
{
    int[] inputs = Console.ReadLine().Split().Select(int.Parse).ToArray();
    list.Add(inputs.ToList());
}
for (int i = 0; i < n - 1; i++)
{
    for (int j = 0; j < list[i].Count; j++)
    {
        if (j > 0)
        {
            list[i+1][j] = Math.Max(list[i+1][j], list[i+1][j] - list[i][j-1] + list[i][j]);
        }
        else
        {
            list[i+1][j] += list[i][j];
        }
        list[i+1][j+1] += list[i][j];
        // Console.Write($"{list[i][j]} ");
    }
    // Console.WriteLine();
}
foreach (var v in list[n-1])
{
    res = Math.Max(res, v);
}
Console.WriteLine(res);