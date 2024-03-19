# Heard of Hex?

- Published: 02/06/2024 (#3/11 in round)
- Category: Cryptography/Steganography
- Points: 70
- Author: Vipin

Find the secret message hidden in the image.

## Attachments

- [HeardOfHex.zip](HeardOfHex.zip)

## Write-up

<details>
<summary>Reveal write-up</summary>

A common procedure on downloaded files, particularly in steganography challenges, is to see if the flag is hidden
directly inside the file using [`strings`](<https://en.wikipedia.org/wiki/Strings_(Unix)>). Therefore, we can run this
command:

```sh
strings xehedoced.jpg
```

This command will print out all sequences of at least 4 printable characters in the file, which results in: (only the
first 10 lines are shown)

```
JFIF
tju{TpApEjoFY8WKiCu8s0Vgr0Y7zdURs9326BDM5Ftc}
I:c:pd
CI"c$
gNRRN-8
#&M:i
'`gH(J\
RM2N
&i gvc
)E!'g
```

The line `tju{TpApEjoFY8WKiCu8s0Vgr0Y7zdURs9326BDM5Ftc}` looks like the format for our flags, which is `csd{flag}`.
Since the characters are all letters, this can be a ROT/Caesar cipher. We can use a tool like CyberChef to decode it.

In [CyberChef](https://gchq.github.io/CyberChef/), the "ROT13 Brute Force" operation is useful if we know it's a ROT
cipher but don't know the number it is being rotated by. We can input input the string and use that operation, which
outputs a series of text, one of which is our flag. Since we know that our flag format starts with `csd`, we can see
that it was rotated 9 times.

```
Amount =  9: csd{CyJyNsxOH8FTrLd8b0Epa0H7imDAb9326KMV5Ocl}
```

Flag: `csd{CyJyNsxOH8FTrLd8b0Epa0H7imDAb9326KMV5Ocl}`

</details>

Write-up by GodderE2D
