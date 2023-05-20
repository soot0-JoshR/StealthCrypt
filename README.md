# StealthCrypt
Hides a key in an image that is sent to the reciever with the ciphertext.
The ciphertext is intended to be another completely legible message.
This way Eve can't actually tell that the message is even encrypted.
And who knows, maybe it isn't encrypted at all.

After building you can run it in a terminal as follows:

## To encipher and hide the key:
./StealthCrypt -m "This is a test" -t "Not really." -i new.png

## To decipher:
./StealthCrypt -d -i new.png -t "This is a test"
