# Geometry Area #2 — Shape Menu

Language: C (C11, gcc)

## Problem statement (as given to students)

Geometry Area #2 — Shape Menu

เลือกชนิดรูป แล้วรับค่าที่จำเป็น จากนั้นคำนวณพื้นที่ (ทศนิยม 2 ตำแหน่ง)
1 = วงกลม (รับรัศมี r)     พื้นที่ = pi*r*r
2 = สี่เหลี่ยม (รับ w, h)    พื้นที่ = w*h
3 = สามเหลี่ยม (รับ base, height) พื้นที่ = 0.5*base*height

รูปแบบ Input : choice แล้วตามด้วยค่าของรูปนั้น
รูปแบบ Output : Area = ...

ตัวอย่าง
Input:
1
5
Output:
Area = 78.54

## Example test

Input (stdin):
```
1
5
```
Expected output must contain:
```
Area = 78.54
```

The program reads from standard input and writes to standard output. Start from the starter file `starter.c` in this folder.
