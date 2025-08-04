using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

public class Algorithm
{
    public static void Main(string[] args)
    {
        StringBuilder sb = new StringBuilder();
        List<int> res = new List<int>();
        List<List<int>> list = new List<List<int>>();
        Queue<Tuple<int, int>> queue = new Queue<Tuple<int, int>>();
        
        int[] input = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int N = input[0];
        int M = input[1];
        int K = input[2];
        int X = input[3];
        int[] visit = new int[N+1];
        for (int i = 0; i <= N; i++)
        {
            list.Add(new List<int>());
        }
        

        for (int i = 0; i < M; i++)
        {
            int[] ab = Console.ReadLine().Split().Select(int.Parse).ToArray();
            int A = ab[0];
            int B = ab[1];
            list[A].Add(B);
        }
        queue.Enqueue(new Tuple<int, int>(0, X));
        visit[X] = 1;
        while (queue.Count > 0)
        {
            Tuple<int, int> item = queue.Dequeue();
            int cnt = item.Item1;
            int idx = item.Item2;
            if (cnt == K)
            {
                res.Add(idx);
                continue;
            }

            foreach (int i in list[idx])
            {
                if (visit[i] == 0)
                {
                    visit[i] = 1;
                    queue.Enqueue(new Tuple<int, int>(cnt+1, i));
                }
            }
        }
        res.Sort();
        if (res.Count == 0) sb.Append(-1);
        else sb.AppendLine(string.Join("\n", res));
        Console.WriteLine(sb.ToString());
    }

    
}