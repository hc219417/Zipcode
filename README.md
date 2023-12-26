# Zipcode
The US Postal Services uses bar codes to represent zip codes in order to sort them quickly using machines. The machine will read the bar code and direct the letter to the right location. Write a C++ program that generates bar codes. The program should read the zip code and determine the complete bar code. The code is represented by a series of short and long bars. The following table shows the barcodes for each digit.

**Value (Encoding)**

`1 (:::||)`

`2 (::|:|)`

`3 (::||:)`

`4 (:|::|)`

`5 (:|:|:)`

`6 (:||::)`

`7 (|:::|)`

`8 (|::|:)`

`9 (|:|::)`

`0 (||:::)`

Use ':' and '|' to represent short and long bars.

A check digit is also added at the end of the barcode. The check digit is determined by totaling all the digits of the zip code and adding a digit that makes the sum divisible by 10. For example, if the sum of all the digits is 38 then the check digit is 2, if the sum is 40 the check digit is 0, etc.

A long bar is added at the beginning and at the end of the barcode (total of 32 bars). The following is an example of the code 45701 (sum = 17, check digit is 3)

`|  :|::|  :|:|:  |:::|  ||:::  :::||  ::||:  |`

Your program should generate the codes repeatedly until the user decides to quit. Your program should print an error message if the zip code entered is invalid (for example, non-digit character, fewer or more than 5 digits).

Your program must include at least the following two functions **(do not change the names or the prototypes)**:

- `string getDigitCode (char digit)`: return a barcode for a single digit
- `int getCheckDigitValue (int sum)`: return the check digit

You are encouraged to add other functions.
