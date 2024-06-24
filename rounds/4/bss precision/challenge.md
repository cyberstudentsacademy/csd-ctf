# bss precision

- Published: 04/28/2024 (#12/14 in round)
- Category: Reverse Engineering/BinEx
- Points: 150
- Author: kolmus

I was working on my overflow skills, but I ran out of time before getting to the end. I left you some notes I took when working on it along with the source code. Good luck!

## Attachments

- [bssprecision](bssprecision)
- [bssprecision.c](bssprecision.c)
- [notes.txt](notes.txt)

## Hint

There was no hint for this challenge.

## Write-up

<details>
<summary>Reveal write-up</summary>

the program takes 14 bytes of input using fgets. the last byte is always null.
the loop that copies the raw input to the `input` buffer stops at the first \n.
this means we effectively get 12 bytes of input without the newline character, hence
why it says "I am going to copy 12 (0xc) bytes of input into `input`."

only 8 bytes have been allocated for the `input` buffer. right after `input` (above in memory)
lives `myval`, an unsigned int consisting of 4 bytes.

```txt
+-----------------------+-------------------------+
|myvar:                0|address:   0x5593be68f028|
|-----------------------|-------------------------+
|input:                 |address:   0x5593be68f020| <- difference of 8 (bytes)
+-----------------------+-------------------------+
```

that means when 12 full bytes are copied into a buffer of 8 bytes, the last 4 bytes will
overflow into myvar. changing myvar is as simple as inputting more than 8 characters.

if we try that with random input, we likely get this message:
`Unfortunately myvar is either too big or or doesn't meet the other requirement. Try again.`

looking at the logic of the if/else block, we can see that we need to change myvar from 0 to something else to get past the first check.

```c
if (myvar == 0) {
    printf("sorry, try again!\n");
```

since both myvar and `secret` are initially 0, changing myvar from 0 to something else will also fail through the second check no matter what.

```c
} else if (myvar == secret) {
    // this is not reached initially...
    printf("You win!\nCheck the notes to get your flag!\n");
```

the third condition is going to be true. `secret` is still 0.

```c
} else if (secret == 0) {
    ...
```

`secret` is then set to the value of myvar. say we input 12345678a, this will be 0x61, `a` in ascii.
`secret` is now 0x61. now a bit shift is performed. all bits get shifted to the right by 4 and
then to the left by 4. let's look at what this does to our `secret`:

```txt
0x61 = 0110 0001
>> 4 = 0000 0110
<< 4 = 0110 0000
secret is now 0x60.
```

essentially, what this does is clear the last 4 bits of the `secret`. now we get to the check that causes the message we got.

```c
if (myvar < 1337 && secret == myvar) {
    ...
```

the first half checks if only one byte made it into `myval`. this works because the smallest 2 byte value that consists of lowercase characters ('aa') is greater than 1337:

```txt
'aa' = 0x6161
0x6161 > 1337
```

the second half checks if myvar would still have its original value after the bit shifts.
in our case this is false. myvar was 0x61 and is now 0x60. if we look at the ascii values of
all of the lowercase characters, zeroing out the last 4 bits will always result in a change,
except for 0x70, which is 'p'. if you're confused about this, think of it like this:

each hex digit is 4 bits. the only value that already has a 0 as the second digit is 0x70.

so the first stage can only be passed with an input that puts 0x70 or 'p' into myvar.
any input like this will work:

```txt
    123456789
--> aabbccddp
--> aaaaaaaap
--> asdfasdfp
```

what they all have in common is the last character. this is the first part of our flag.

now `secret` is updated again. it is multiplied by some hex value. after that we should
be able to see its value: `1684369008 (0x64656e70)`. the program wants us to change myvar to
that value. If we get there, we meet reach the win condition.

to get myvar to be `0x64656e70`, we need input the characters that represent the bytes of the value so that they overflow into myvar.

```txt
0x64 = 'd'
0x65 = 'e'
0x6e = 'n'
0x70 = 'p'
```

now you might think that something like this should do the trick:

```txt
    12345678....
--> abcdefghdenp
--> aabbccdddenp
```

but it doesn't. the notes say to remember endianess. since bytes are stored in memory in reverse order, we need to reverse this part of the input like so:

```txt
    12345678....
--> abcdefghpned
--> aaaaaaaapned
```

the last 4 characters of this second input are the second part of the flag.
'p' + 'pned' = 'ppned'

so the flag is csd{ppned}

Flag: `csd{ppned}`

</details>

Write-up by kolmus
