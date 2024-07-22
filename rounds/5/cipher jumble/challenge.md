# cipher jumble

- Published: 05/03/2024 (#1/7 in round)
- Category: Cryptography
- Points: 25
- Author: Vipin

my friend got himself into a jumble, when he tried to decode the text, he kept encoding it.

## Attachments

- [enc](enc)

## Hint

This hint costed 5 points.

<details>
<summary>Reveal hint</summary>

Look into Base85 & Vignere

</details>

## Write-up

<details>
<summary>Reveal write-up</summary>

This is a beginner challenge that utilizes 2 different encryption methods to hide the flag. To obtain the flag, we can start by decrypting from Base85 as popular tools such as **dcode.fr** and **Cyberchef** say that it is Base85.

```Key: prettygirl Cipher: rjh{1_4F_F4I1T6_7P15_TS4113C63_1E_117_G1455}```

After decrypting from Base85 we recieve the string above which provides us with a key and ciphertext. The most common key-based cipher is ***Vignere***, we can use Cyberchef's Vignere decoder to obtain the flag by providingthe key and ciphertext. [Vignere Decoded Link](https://gchq.github.io/CyberChef/#recipe=Vigen%C3%A8re_Decode('prettygirl')&input=cmpoezFfNEZfRjRJMVQ2XzdQMTVfVFM0MTEzQzYzXzFFXzExN19HMTQ1NX0&oeol=FF)

Flag: ```csd{1_4M_M4K1N6_7H15_CH4113N63_1N_117_C1455}```


</details>

Write-up by [Vipin](https://vipin.xyz)