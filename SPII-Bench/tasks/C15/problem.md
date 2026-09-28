# Simple Bank Account #3 — With Validation

Language: C (C11, gcc)

## Problem statement (as given to students)

Simple Bank Account #3 — With Validation

เหมือนข้อ #2 แต่เพิ่มการตรวจสอบ:
- จำนวนเงินต้องมากกว่า 0 ไม่งั้นพิมพ์ Invalid amount (ไม่นับรายการ)
- ถอนเกินยอดคงเหลือ พิมพ์ Insufficient funds (ไม่นับรายการ)
- เมื่อออก (4) แสดงจำนวนรายการที่สำเร็จ และยอดคงเหลือสุดท้าย

ตัวอย่าง
Input:
1
500
2
800
2
300
1
-50
4
Output:
Deposited 500, Balance = 500
Insufficient funds
Withdrew 300, Balance = 200
Invalid amount
Transactions = 2
Final balance = 200

## Example test

Input (stdin):
```
1
500
2
800
2
300
1
-50
4
```
Expected output must contain:
```
Deposited 500, Balance = 500
Insufficient funds
Withdrew 300, Balance = 200
Invalid amount
Transactions = 2
Final balance = 200
```

The program reads from standard input and writes to standard output. Start from the starter file `starter.c` in this folder.
