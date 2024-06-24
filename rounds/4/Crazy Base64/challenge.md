# Crazy Base64

- Published: 04/21/2024 (#10/14 in round)
- Category: Misc.
- Points: 145
- Author: ladderlogic

Base64 with a GIANT twist

## Attachments

- [chall](chall)

## Hint

This hint costed 5 points.

<details>
<summary>Reveal hint</summary>

The letters do not repeat next to one ie no "ee"

This is one of those challenges where you could do this manually, but you would hate yourself.

</details>

## Write-up

<details>
<summary>Reveal write-up</summary>

- Either use a non-linewrapping text editor and type out the big letters manually, or use a script to do it for you.

```py
def remove_consecutive_duplicates(s):
    result = [s[0]]
    for char in s[1:]:
        if char != result[-1]:
            result.append(char)
    return ''.join(result) 

with open('chall', 'r') as file:
    for line in file:
        new_string = remove_consecutive_duplicates(line.replace(" ", ""))
        print(new_string)
        break 
```

- This script only works with the third line of the file. you first need to remove every other line.
- You also need to add one more '=' at the end to get the correct base64 string.
- `GhpcyBpcyBnb2luZyB0byBiZSBhIHJlYWxseSBjb29sIGZsYWcgaWYgeW91IGNhbiBzb2x2ZSB0aGlzLiBGTEFHOiBjc2R7QjFnX1QzeHR9IERvZXNuJ3QgdGhlIGJpZyB0ZXh0IG1ha2UgdGhpcyByZWFsbHkgZnVuLg==`
- base64 decode it to get the flag

Flag: `csd{B1g_T3xt}`

</details>

Write-up by ladderlogic