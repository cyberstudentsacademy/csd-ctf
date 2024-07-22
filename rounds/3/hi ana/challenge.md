# hi ana

- Published: 03/10/2024 (#1/6 in round)
- Category: OSINT
- Points: 30
- Author: Vipin

Find the Registrar IANA ID for the domain
```vipinb.xyz```

Flag Format: csd{sha256 hash of the ID}

## Attachments

- ```vipinb.xyz```

## Hint

This hint costed 10 points.

<details>
<summary>Reveal hint</summary>

whois

</details>

## Write-up

<details>
<summary>Reveal write-up</summary>

To find information about the domain we can use the ```whois``` command. Since we are finding the IANA ID, we can ```grep``` for that. Below is the offical solve method.

```bash:Terminal
❯ whois vipinb.xyz | grep "IANA ID"
Registrar IANA ID: 1636
Registrar IANA ID: H2712453
❯ echo -n 'H2712453' | shasum -a 256 | awk '{print "csd{"$1"}"}'
csd{39d569bc0fc532d2993920f1f1bf0fabf82b510d44471374045672d7a15f33b0}
```

Flag: `csd{39d569bc0fc532d2993920f1f1bf0fabf82b510d44471374045672d7a15f33b0}` or `csd{245db7164aace830256c713e17486f1785096c86049d6409349fff5f810da253}`

</details>

Write-up by [Vipin](https://vipin.xyz)