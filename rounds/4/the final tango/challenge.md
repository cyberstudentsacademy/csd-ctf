# the final tango

- Published: 05/01/2024 (#14/14 in round)
- Category: Forensics
- Points: 135
- Author: Vipin

Luis Santiago Bautista is a milonguero who dances to **all** kind of music like **R**eggae, **G**ospel, and **B**luegrass.

## Attachments

- [final.jpeg.zip](final.jpeg.zip)

## Hint

This hint costed 20 points.

<details>
<summary>Reveal hint</summary>

Look into LSB & if you are using an online tool, maybe select all the bits...

</details>

## Write-up

<details>
<summary>Reveal write-up</summary>

- The challenge provides a zip file containing an image file named `final.jpeg`
- Run `zsteg -a final.jpeg | grep csd{`

Flag: `csd{1_H4V3_11K3_F1F7Y_811110N_73575_7H15_M0N7H}`

</details>

Write-up by kolmus
