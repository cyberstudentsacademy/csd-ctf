# 1364 Rotten Apple

<<<<<<< HEAD
- Published: 04/04/2024 (#2/14 in round)
- Category: Steganography
- Points: 25
- Author: iARX

Someone sent me a bunch of random letters, can you decode it?

Tip: Flag is in csd{} format

## Attachments

- `I1EBG2RlIKqvE1cIHacerIEHEGIuIxMRIJgnJJIfn3qKFTkuMSMjE09JGx5GExcgISMFG09ECG0=`

## Hint

This hint costed 10 points.

<details>
<summary>Reveal hint</summary>

Focus on the title... 13 & 64? Rotten apples? Could those mean anything? 

</details>

## Write-up

<details>
<summary>Reveal write-up</summary>

A simple decoding challenge utilizing basic cryptography, we can solve this by decoding from **ROT 13** initially and then repeatedly decoding from **Base64**. 

[Cyberchef recipe](https://gchq.github.io/CyberChef/#recipe=ROT13(true,true,false,13)From_Base64('A-Za-z0-9%2B/%3D',true,false)From_Base64('A-Za-z0-9%2B/%3D',true,false)From_Base64('A-Za-z0-9%2B/%3D',true,false)&input=STFFQkcyUmxJS3F2RTFjSUhhY2VySUVIRUdJdUl4TVJJSmduSkpJZm4zcUtGVGt1TVNNakUwOUpHeDVHRXhjZ0lTTUZHMDlFQ0cwPQ) to decode.

Flag: ```csd{I_Lov3_b@$E_64_&nd_R0t_13}```


</details>

Write-up by [Vipin](https://vipinb.xyz)