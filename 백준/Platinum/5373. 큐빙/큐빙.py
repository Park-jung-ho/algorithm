from collections import deque
import sys
input = sys.stdin.readline



T = int(input())
for i in range(T):
    UB, UL, UR, UF = 'w','w','w','w'
    DB, DL, DR, DF = 'y','y','y','y'
    FU, FL, FR, FD = 'r','r','r','r'
    BU, BL, BR, BD = 'o','o','o','o'
    LU, LD, LF, LB = 'g','g','g','g'
    RU, RD, RF, RB = 'b','b','b','b'
    ULB, URB, ULF, URF = 'w','w','w','w'
    DLB, DRB, DLF, DRF = 'y','y','y','y'
    FLU, FLD, FRU, FRD = 'r','r','r','r'
    BLU, BLD, BRU, BRD = 'o','o','o','o'
    LUB, LUF, LDB, LDF = 'g','g','g','g'
    RUB, RUF, RDB, RDF = 'b','b','b','b'
    
    N = int(input())
    arr = list(input().split())
    for i in arr:
        if i[0] == 'U':
            if i[1] == '-':
                n = 1
            else:
                n = 3
            for _ in range(n):
                UB, UR, UF, UL = UR, UF, UL, UB
                BU, RU, FU, LU = RU, FU, LU, BU
                ULB, URB, URF, ULF = URB, URF, ULF, ULB
                BLU, RUB, FRU, LUF = RUB, FRU, LUF, BLU
                BRU, RUF, FLU, LUB = RUF, FLU, LUB, BRU
        if i[0] == 'D':
            if i[1] == '+':
                n = 1
            else:
                n = 3
            for _ in range(n):
                DB, DR, DF, DL = DR, DF, DL, DB
                BD, RD, FD, LD = RD, FD, LD, BD
                DLB, DRB, DRF, DLF = DRB, DRF, DLF, DLB
                BLD, RDB, FRD, LDF = RDB, FRD, LDF, BLD
                BRD, RDF, FLD, LDB = RDF, FLD, LDB, BRD
        if i[0] == 'L':
            if i[1] == '-':
                n = 1
            else:
                n = 3
            for _ in range(n):
                LU, LF, LD, LB = LF, LD, LB, LU
                UL, FL, DL, BL = FL, DL, BL, UL
                LUB, LUF, LDF, LDB = LUF, LDF, LDB, LUB
                ULB, FLU, DLF, BLD = FLU, DLF, BLD, ULB
                ULF, FLD, DLB, BLU = FLD, DLB, BLU, ULF
        if i[0] == 'R':
            if i[1] == '+':
                n = 1
            else:
                n = 3
            for _ in range(n):
                RU, RF, RD, RB = RF, RD, RB, RU
                UR, FR, DR, BR = FR, DR, BR, UR
                RUB, RUF, RDF, RDB = RUF, RDF, RDB, RUB
                URB, FRU, DRF, BRD = FRU, DRF, BRD, URB
                URF, FRD, DRB, BRU = FRD, DRB, BRU, URF
        if i[0] == 'F':
            if i[1] == '-':
                n = 1
            else:
                n = 3
            for _ in range(n):
                FU, FR, FD, FL = FR, FD, FL, FU
                UF, RF, DF, LF = RF, DF, LF, UF
                FLU, FRU, FRD, FLD = FRU, FRD, FLD, FLU
                ULF, RUF, DRF, LDF = RUF, DRF, LDF, ULF
                URF, RDF, DLF, LUF = RDF, DLF, LUF, URF
        if i[0] == 'B':
            if i[1] == '+':
                n = 1
            else:
                n = 3
            for _ in range(n):
                BU, BR, BD, BL = BR, BD, BL, BU
                UB, RB, DB, LB = RB, DB, LB, UB
                BLU, BRU, BRD, BLD = BRU, BRD, BLD, BLU
                ULB, RUB, DRB, LDB = RUB, DRB, LDB, ULB
                URB, RDB, DLB, LUB = RDB, DLB, LUB, URB
        



    up = [[ULB,UB,URB],[UL,'w',UR],[ULF,UF,URF]]
    for i in up:
        print(''.join(i))