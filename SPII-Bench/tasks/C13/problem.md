# Geometry Area #3 — Total Area

Language: C (C11, gcc)

## Problem statement (as given to students)

Geometry Area #3 — Total Area

รับจำนวนรูป n แล้วแต่ละบรรทัดเป็นข้อมูลของรูปหนึ่ง (type แล้วตามด้วยค่า)
type 1 = วงกลม (r), 2 = สี่เหลี่ยม (w h), 3 = สามเหลี่ยม (base height)
รวมพื้นที่ทั้งหมดแล้วแสดงผล (ทศนิยม 2 ตำแหน่ง)

ตัวอย่าง
Input:
3
1 2
2 3 4
3 6 2
Output:
Total area = 30.57
(อธิบาย: วงกลม r=2 -> 12.57, สี่เหลี่ยม 3x4 -> 12, สามเหลี่ยม 0.5*6*2 -> 6 รวม 30.57)

## Example test

Input (stdin):
```
3
1 2
2 3 4
3 6 2
```
Expected output must contain:
```
Total area = 30.57
```

The program reads from standard input and writes to standard output. Start from the starter file `starter.c` in this folder.
