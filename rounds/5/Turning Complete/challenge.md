# Turning Complete

- Published: 05/14/2024 (#5/7 in round)
- Category: Cryptography
- Points: 200
- Author: Vipin

Break the cipher, there is only 3 rotors and no plug board. Flag uses ( instead of {

## Attachments

- ```MORMSJBLGRWAREWDAPXGVYQCCNZB```

## Hint

This hint costed 50 points.

<details>
<summary>Reveal hint</summary>

You might have to write your own code or modify code on the internet. This is a basic engima cipher, using the old rotors

The reflector is C

The parathesis are encoded using a common German system of encoding which there are two. Try both

Here is a tool you can use to help solve this challenge [https://github.com/raspberrypilearning/octapi-brute-force-enigma/blob/master/en/resources/enigma_bf_standalone.py](https://github.com/raspberrypilearning/octapi-brute-force-enigma/blob/master/en/resources/enigma_bf_standalone.py) you will need to change the code for it to work

</details>

## Write-up

<details>
<summary>Reveal write-up</summary>

We will be modifying [this](https://github.com/raspberrypilearning/octapi-brute-force-enigma/blob/master/en/resources/enigma_bf_standalone.py) script to decode the engima cipher. 

Solve Script:
```python
rotor = [ 	"I II III", 	"I II IV", 	"I II V",  	"I III II",
		"I III IV", 	"I III V", 	"I IV II", 	"I IV III",
		"I IV V", 	"I V II", 	"I V III", 	"I V IV",
		"II I III", 	"II I IV", 	"II I V", 	"II III I",
		"II III IV", 	"II III V", 	"II IV I", 	"II IV III",
		"II IV V", 	"II V I", 	"II V III", 	"II V IV",
		"III I II",	"III I IV",	"III I V",	"III II I",
		"III II IV", 	"III II V",	"III IV I",	"III IV II",
		"III IV V", 	"IV I II",	"IV I III",	"IV I V",
		"IV II I",	"IV II III",	"IV I V",	"IV II I",
		"IV II III",	"IV II V",	"IV III I",	"IV III II",
		"IV III V",	"IV V I",	"IV V II",	"IV V III",
		"V I II",	"V I III",	"V I IV",	"V II I",
		"V II III", 	"V II IV",	"V III I",	"V III II",
		"V III IV",	"V IV I",	"V IV II",	"V IV III"	]

#
# This function does an exhaust search over the list of possible
# rotor selections
#
def find_rotor_start( rotor_choice, ciphertext, cribtext ):

    from enigma.machine import EnigmaMachine

    alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

    machine = EnigmaMachine.from_key_sheet(
       rotors=rotor_choice,
       reflector='B',
       ring_settings='1 1 1',					
       plugboard_settings='')	


    # do an exhaust search over all possible rotor starting positions
    for i in range(len(alphabet)):            # search for rotor 1 start position
        for j in range(len(alphabet)):        # search for rotor 2 start position
            for k in range(len(alphabet)):    # search for rotor 3 start position
                # generate a possible rotor start position
                start_pos = alphabet[i] + alphabet[j] + alphabet[k]

                # set machine initial starting position and attempt decrypt
                machine.set_display(start_pos)
                plaintext = machine.process_text(ciphertext)

                # check if decrypt is the same as the crib text
                if (cribtext in plaintext):
                    print(plaintext)
                    return( rotor_choice, start_pos )

    return( rotor_choice, "null" )


# main loop
if __name__ == '__main__':
    ciphertext = "CHCVWOCMUIKXTICKQXEQFPBVARWGEVXNHKGVOAYOURQUWURWDLUSGRVLDZAUKNLLGLRVVAE"
    cribtext = "YOURFLAG"

    print(( "Brute force crypt attack on Enigma message %s using crib %s" % (ciphertext, cribtext) ))

    for rotor_setting in rotor:
        print(( "Trying rotors %s..." % (rotor_setting) ))
        rotor_choice, start_pos = find_rotor_start( rotor_setting, ciphertext, cribtext )
        if (start_pos != "null"):
            print(( "Machine setting found: rotors %s, message key was %s, using crib %s" % (rotor_choice, start_pos, cribtext) ))
```

Flag: `csd(wwiicipherbreaker)
CSD(WWIICIPHERBREAKER)
`

</details>

Write-up by [Logix](https://ics.red/a)