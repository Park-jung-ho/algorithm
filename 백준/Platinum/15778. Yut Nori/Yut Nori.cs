using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Algorithm
{
    public class p15778
    {
        // .. -> AB 
        // .. -> CD
        // abcd / ABCD
        // 모서리에서는 거리가 빠른곳으로 이동
        // 도착지점에 상대편 말이 있으면 처음으로 보냄
        // 이동 시 같은 자리에 자기 편의 말 2개 이상 존재하면 같이 움직임
        public class map
        {
            public char[] m = new char[] { '.', '.', '.', '.' };
        }
        public static List<map> m_list = new List<map>();
        public static List<List<int>> road = new List<List<int>>
        {
            new List<int> {0,1,2,3,4,5,20,21,22,27,28,29},
            new List<int> {0,1,2,3,4,5,6,7,8,9,10,25,26,22,27,28,29},
            new List<int> {0,1,2,3,4,5,20,21,22,23,24,15,16,17,18,19,29},
            new List<int> {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,29}
        };

        public static Dictionary<char, int> check = new Dictionary<char, int>()
        {
            {'a',0},{'b',0},{'c',0},{'d',0},
            {'A',0},{'B',0},{'C',0},{'D',0}
        };
       
        public static string[] yutpan = new string[32]
        {"..----..----..----..----..----..",
         "..    ..    ..    ..    ..    ..",
         "| \\                          / |",
         "|  \\                        /  |",
         "|   \\                      /   |",
         "|    ..                  ..    |",
         "..   ..                  ..   ..",
         "..     \\                /     ..",
         "|       \\              /       |",
         "|        \\            /        |",
         "|         ..        ..         |",
         "|         ..        ..         |",
         "..          \\      /          ..",
         "..           \\    /           ..",
         "|             \\  /             |",
         "|              ..              |",
         "|              ..              |",
         "|             /  \\             |",
         "..           /    \\           ..",
         "..          /      \\          ..",
         "|         ..        ..         |",
         "|         ..        ..         |",
         "|        /            \\        |",
         "|       /              \\       |",
         "..     /                \\     ..",
         "..   ..                  ..   ..",
         "|    ..                  ..    |",
         "|   /                      \\   |",
         "|  /                        \\  |",
         "| /                          \\ |",
         "..    ..    ..    ..    ..    ..",
         "..----..----..----..----..----.."
        };
        public static void Main(string[] args)
        {
            int n = Console.ReadLine().Split().Select(int.Parse).ToArray()[0];
            for (int i = 0; i < 30; i++)
            {
                m_list.Add(new map());
            }

            for (int i = 0; i < n; i++)
            {
                string[] input = Console.ReadLine().Split().ToArray();
                //Console.WriteLine($"{input[0]} | {input[1]}");

                int cnt = CheckYut(input[1]);

                Move(input[0][0], cnt);
            }
            Result();
            
        }
        public static int CheckYut(string yut)
        {
            int cnt = 0;

            foreach (char s in yut)
            {
                if (s == 'F') cnt++;
            }

            if (cnt == 0) return 5;

            return cnt;
        }
        public static void Move(char m, int moveCnt)
        {
            bool[] canMove = new bool[4] { false, false, false, false };
            if (m == 'a' || m == 'A') canMove[0] = true;
            if (m == 'b' || m == 'B') canMove[1] = true;
            if (m == 'c' || m == 'C') canMove[2] = true;
            if (m == 'd' || m == 'D') canMove[3] = true;

            bool moveSmall = false;
            if (m >= 'a' && m <= 'd')
            {
                moveSmall = true;
            }
            int startIdx = check[m];
            for (int i = 0; i < 4; i++)
            {
                char c = m_list[startIdx].m[i];
                
                bool isSmall = false;
                if (c >= 'a' && c <= 'd')
                {
                    isSmall = true;
                }
                if (c != '.' && moveSmall == isSmall)
                {
                    canMove[i] = true;
                }
            }
            int currentIdx = 0;
            int r = 0;
            if (startIdx == 22 || startIdx == 27 || startIdx == 28) r = 0;
            else if (startIdx == 10 || startIdx == 25 || startIdx == 26) r = 1;
            else if (startIdx == 5 || (startIdx >= 20 && startIdx <= 24)) r = 2;
            else r = 3;
            int t = 0;
            for (int i = 0; i < road[r].Count; i++)
            {
                if (road[r][i] == startIdx)
                {
                    t = i;
                    break;
                }
            }
            for (int i = 0; i < 4; i++)
            {
                if (canMove[i])
                {
                    char cc = 'A';
                    if (moveSmall) cc = 'a';
                    cc = (char)(cc + i);
                    check[cc] = 0;
                    m_list[startIdx].m[i] = '.';
                }
            }
            for (int i = t+1; i < road[r].Count; i++)
            {
                moveCnt--;
                if (moveCnt == 0)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        char c = m_list[road[r][i]].m[j];
                        bool isSmall = false;
                        if (c >= 'a' && c <= 'd')
                        {
                            isSmall = true;
                        }
                        if (c != '.' && moveSmall != isSmall)
                        {
                            check[c] = 0;
                            m_list[road[r][i]].m[j] = '.';
                        }
                        if (canMove[j])
                        {
                            char cc = 'A';
                            if (moveSmall) cc = 'a';
                            cc = (char)(cc + j);
                            check[cc] = road[r][i];
                            m_list[road[r][i]].m[j] = cc;
                        }
                    }
                    break;
                }
            }
        }
        public static void Result()
        {
            StringBuilder sb = new StringBuilder(yutpan[0]);
            sb[0] = m_list[10].m[0];
            sb[1] = m_list[10].m[1];
            sb[6] = m_list[9].m[0];
            sb[7] = m_list[9].m[1];
            sb[12] = m_list[8].m[0];
            sb[13] = m_list[8].m[1];
            sb[18] = m_list[7].m[0];
            sb[19] = m_list[7].m[1];
            sb[24] = m_list[6].m[0];
            sb[25] = m_list[6].m[1];
            sb[30] = m_list[5].m[0];
            sb[31] = m_list[5].m[1];
            Console.WriteLine(sb);
            sb = new StringBuilder(yutpan[1]);
            sb[0] = m_list[10].m[2];
            sb[1] = m_list[10].m[3];
            sb[6] = m_list[9].m[2];
            sb[7] = m_list[9].m[3];
            sb[12] = m_list[8].m[2];
            sb[13] = m_list[8].m[3];
            sb[18] = m_list[7].m[2];
            sb[19] = m_list[7].m[3];
            sb[24] = m_list[6].m[2];
            sb[25] = m_list[6].m[3];
            sb[30] = m_list[5].m[2];
            sb[31] = m_list[5].m[3];
            Console.WriteLine(sb);
            Console.WriteLine(yutpan[2]);
            Console.WriteLine(yutpan[3]);
            Console.WriteLine(yutpan[4]);
            sb = new StringBuilder(yutpan[5]);
            sb[5] = m_list[25].m[0];
            sb[6] = m_list[25].m[1];
            sb[25] = m_list[20].m[0];
            sb[26] = m_list[20].m[1];
            Console.WriteLine(sb);
            sb = new StringBuilder(yutpan[6]);
            sb[0] = m_list[11].m[0];
            sb[1] = m_list[11].m[1];
            sb[5] = m_list[25].m[2];
            sb[6] = m_list[25].m[3];
            sb[25] = m_list[20].m[2];
            sb[26] = m_list[20].m[3];
            sb[30] = m_list[4].m[0];
            sb[31] = m_list[4].m[1];
            Console.WriteLine(sb);
            sb = new StringBuilder(yutpan[7]);
            sb[0] = m_list[11].m[2];
            sb[1] = m_list[11].m[3];
            sb[30] = m_list[4].m[2];
            sb[31] = m_list[4].m[3];
            Console.WriteLine(sb);
            Console.WriteLine(yutpan[8]);
            Console.WriteLine(yutpan[9]);
            sb = new StringBuilder(yutpan[10]);
            sb[10] = m_list[26].m[0];
            sb[11] = m_list[26].m[1];
            sb[20] = m_list[21].m[0];
            sb[21] = m_list[21].m[1];
            Console.WriteLine(sb);
            sb = new StringBuilder(yutpan[11]);
            sb[10] = m_list[26].m[2];
            sb[11] = m_list[26].m[3];
            sb[20] = m_list[21].m[2];
            sb[21] = m_list[21].m[3];
            Console.WriteLine(sb);
            sb = new StringBuilder(yutpan[12]);
            sb[0] = m_list[12].m[0];
            sb[1] = m_list[12].m[1];
            sb[30] = m_list[3].m[0];
            sb[31] = m_list[3].m[1];
            Console.WriteLine(sb);
            sb = new StringBuilder(yutpan[13]);
            sb[0] = m_list[12].m[2];
            sb[1] = m_list[12].m[3];
            sb[30] = m_list[3].m[2];
            sb[31] = m_list[3].m[3];
            Console.WriteLine(sb);
            Console.WriteLine(yutpan[14]);
            sb = new StringBuilder(yutpan[15]);
            sb[15] = m_list[22].m[0];
            sb[16] = m_list[22].m[1];
            Console.WriteLine(sb);
            sb = new StringBuilder(yutpan[16]);
            sb[15] = m_list[22].m[2];
            sb[16] = m_list[22].m[3];
            Console.WriteLine(sb);
            Console.WriteLine(yutpan[17]);
            sb = new StringBuilder(yutpan[18]);
            sb[0] = m_list[13].m[0];
            sb[1] = m_list[13].m[1];
            sb[30] = m_list[2].m[0];
            sb[31] = m_list[2].m[1];
            Console.WriteLine(sb);
            sb = new StringBuilder(yutpan[19]);
            sb[0] = m_list[13].m[2];
            sb[1] = m_list[13].m[3];
            sb[30] = m_list[2].m[2];
            sb[31] = m_list[2].m[3];
            Console.WriteLine(sb);
            sb = new StringBuilder(yutpan[20]);
            sb[10] = m_list[23].m[0];
            sb[11] = m_list[23].m[1];
            sb[20] = m_list[27].m[0];
            sb[21] = m_list[27].m[1];
            Console.WriteLine(sb);
            sb = new StringBuilder(yutpan[21]);
            sb[10] = m_list[23].m[2];
            sb[11] = m_list[23].m[3];
            sb[20] = m_list[27].m[2];
            sb[21] = m_list[27].m[3];
            Console.WriteLine(sb);
            Console.WriteLine(yutpan[22]);
            Console.WriteLine(yutpan[23]);
            sb = new StringBuilder(yutpan[24]);
            sb[0] = m_list[14].m[0];
            sb[1] = m_list[14].m[1];
            sb[30] = m_list[1].m[0];
            sb[31] = m_list[1].m[1];
            Console.WriteLine(sb);
            sb = new StringBuilder(yutpan[25]);
            sb[0] = m_list[14].m[2];
            sb[1] = m_list[14].m[3];
            sb[5] = m_list[24].m[0];
            sb[6] = m_list[24].m[1];
            sb[25] = m_list[28].m[0];
            sb[26] = m_list[28].m[1];
            sb[30] = m_list[1].m[2];
            sb[31] = m_list[1].m[3];
            Console.WriteLine(sb);
            sb = new StringBuilder(yutpan[26]);
            sb[5] = m_list[24].m[2];
            sb[6] = m_list[24].m[3];
            sb[25] = m_list[28].m[2];
            sb[26] = m_list[28].m[3];
            Console.WriteLine(sb);
            Console.WriteLine(yutpan[27]);
            Console.WriteLine(yutpan[28]);
            Console.WriteLine(yutpan[29]);
            sb = new StringBuilder(yutpan[30]);
            sb[0] = m_list[15].m[0];
            sb[1] = m_list[15].m[1];
            sb[6] = m_list[16].m[0];
            sb[7] = m_list[16].m[1];
            sb[12] = m_list[17].m[0];
            sb[13] = m_list[17].m[1];
            sb[18] = m_list[18].m[0];
            sb[19] = m_list[18].m[1];
            sb[24] = m_list[19].m[0];
            sb[25] = m_list[19].m[1];
            sb[30] = m_list[29].m[0];
            sb[31] = m_list[29].m[1];
            Console.WriteLine(sb);
            sb = new StringBuilder(yutpan[31]);
            sb[0] = m_list[15].m[2];
            sb[1] = m_list[15].m[3];
            sb[6] = m_list[16].m[2];
            sb[7] = m_list[16].m[3];
            sb[12] = m_list[17].m[2];
            sb[13] = m_list[17].m[3];
            sb[18] = m_list[18].m[2];
            sb[19] = m_list[18].m[3];
            sb[24] = m_list[19].m[2];
            sb[25] = m_list[19].m[3];
            sb[30] = m_list[29].m[2];
            sb[31] = m_list[29].m[3];
            Console.WriteLine(sb);
        }
    }
}