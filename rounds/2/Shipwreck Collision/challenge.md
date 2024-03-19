# Shipwreck Collision

- Published: 02/12/2024 (#8/11 in round)
- Category: Cryptography
- Points: 100
- Author: GodderE2D

Submit an image that, for a robot, looks identical to the image, but totally different to a human eye...

Tip: You can view the source code of the site [here](https://replit.com/@GodderE2D/CSCTF-Shipwreck-Collision).

Tested by Vipin

## Attachments

- https://shipwreck-collision-csctf.bsr.gg/

> [!IMPORTANT]  
> The website is no longer online, please visit the
> [Replit Repl](https://replit.com/@GodderE2D/CSCTF-Shipwreck-Collision) and fork it to try the challenge.

## Hint

This hint costed 25 points.

<details>
<summary>Reveal hint</summary>

A [hash collision](https://en.wikipedia.org/wiki/Hash_collision) is a rare occurrence where two files share the same
hash.

Try looking at the [source code](https://replit.com/@GodderE2D/CSCTF-Shipwreck-Collision), are you able to know which
hashing algorithm is being used?

Knowing this, you can search for common hash collisions for the specific algorithm.

</details>

## Write-up

<details>
<summary>Reveal write-up</summary>

When visiting the website, we see a picture of a shipwreck. We can try to submit another image, or the same image, but
those don't work.

Taking a look at the source code, we can see that the MD5 hashes of the images are being compared.

<!-- prettier-ignore-start -->
```js
// Maybe this isn't the most secure hashing algorithm...
const originalHash = crypto
  .createHash("md5")
  .update(new Uint8Array(originalBuffer))
  .digest("hex");

const userHash = crypto
  .createHash("md5")
  .update(new Uint8Array(buffer))
  .digest("hex");

if (originalHash !== userHash) {
  return res.send("Beep boop - they don't look like the same image to me.");
}
```
<!-- prettier-ignore-end -->

From this, we can exploit the fact that [MD5 has known collisions](https://www.mscs.dal.ca/~selinger/md5collision/). We
can use a [preimage attack](https://en.wikipedia.org/wiki/Preimage_attack) to get the flag.

Simply searching on Google "md5 hash collision examples" brings us to
[this page](https://crypto.stackexchange.com/questions/1434/are-there-two-known-strings-which-have-the-same-md5-hash-value),
with the same image of the ship. We can see the other image attached, so we can upload that image to the site to get the
flag.

Flag: `csd{MD5_C0111D3D_1N70_7H3_P14N3_4ND_5H1P}`

</details>

Write-up by GodderE2D
