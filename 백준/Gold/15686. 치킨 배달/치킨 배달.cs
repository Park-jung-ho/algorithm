using System;
using System.Collections.Generic;
using System.Linq;

public class Algorithm
{
    public static void Main(string[] args)
    {
        int[] input = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int N = input[0];
        int M = input[1];
        int res = int.MaxValue;
        List<Tuple<int, int>> Home = new List<Tuple<int, int>>();
        List<Tuple<int, int>> Chicken = new List<Tuple<int, int>>();
        List<int> clist = new List<int>();

        for (int i = 1; i <= N; i++)
        {
            int[] row = Console.ReadLine().Split().Select(int.Parse).ToArray();
            for (int j = 1; j <= N; j++)
            {
                if (row[j - 1] == 1)
                {
                    Home.Add(new Tuple<int, int>(i, j));
                }

                if (row[j - 1] == 2)
                {
                    Chicken.Add(new Tuple<int, int>(i, j));
                }
            }
        }

        void ChooseChicken(int idx)
        {
            if (clist.Count == M)
            {
                CheckDistance();
                return;
            }
            for (int i = idx; i < Chicken.Count; i++)
            {
                clist.Add(i);
                ChooseChicken(i+1);
                clist.RemoveAt(clist.Count - 1);
            }
        }

        void CheckDistance()
        {
            int cnt = 0;
            foreach (Tuple<int, int> h in Home)
            {
                int tmp = int.MaxValue;
                foreach (int i in clist)
                {
                    tmp = Math.Min(tmp, (Math.Abs(h.Item1 - Chicken[i].Item1) + Math.Abs(h.Item2 - Chicken[i].Item2)));
                }
                cnt += tmp;
                if (cnt >= res) break;
            }
            res = Math.Min(res, cnt);
        }

        ChooseChicken(0);
        Console.WriteLine(res);
    }
}