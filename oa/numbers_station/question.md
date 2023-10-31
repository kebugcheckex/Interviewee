# Numbers Station

A friend asks you to tune into a local numbers station, a radio station that is publishing a coded message. They say they've had a tip on how to decipher the messages the station is publishing, but want your help in writing a program that will do the deciphering. You start listening to the station and notice that in each voice sample the person reads out a number followed by letter or a hyphen `-`. The numbers don't seem to be in any particular order. You decide that you're going to help write the program, so your friend shares what the tip was.

- Every sample will contain a number which can be used to put the message in order (sequence ID).
- Every message only contains the letters `a` to `z`.
- A complete message is a continuous set of characters surrounded by two `-` characters.
- Sometimes a message is never completed (missing sequence IDs)
- Once you've completed a full message, all messasges completed later with a lower sequence ID are no longer useful and should not be output (you should only output the latest message)
- If two full messages are completed at the same time, then you should output only the message containing higher sequence IDs.
- A full broadcast can contain multiple complete messages and you will need to output each of them.

## Function Description

You are to implement the function `ProcessSample` that takes:

- a sequence number for the sample,
- the character for the sample.

Whenever a full message is completed you should call the `OnMessageComplete` function with the completed message.

## Constraints

- 0 < sequence id < 2^64 - 1
- number of messages >= 1

## Input Format

For each line, the first string is the sequence number associated with the sample, the second character is the character related to the sequence number.

## Sample Case 0

### Sample Input

```
1 -
2 h
3 e
4 l
5 l
6 o
7 -
8 b
```

### Sample Output

```
hello
```

### Explanation

When the samples are placed in order according to their sequence IDs we get the following `-hello-b`. There is one complete message here (between the `-` characters) so it is output.

## Sample Case 1

### Sample Input

```
1 -
2 b
3 y
5 -
6 h
7 i
8 -
4 e
```

### Sample Output

```
hi
```

### Explanation

When the samples are placed in order according to their sequence IDs we get the following, `-bye-hi-`. This broadcast contains two complete messages (`bye` and `hi`), but because the second complete messages (`hi`) was completed before the first (`bye`), we only output the later message (`hi`).

## Sample Case 2

### Sample Input

```
1 -
2 h
3 e
4 l
5 l
6 o
7 -
8 b
9 y
10 e
11 -
```

### Sample Output

```
hello
bye
```

### Explanation

When the samples are placed in order according to their sequence IDs we get the following, `-hello-bye-`. This broadcast contains two complete messsages (`hello` and `bye`), since the first complete message (`hello`) is finished first, we output it. Then when sequence ID `11 -` completes the second message (`bye`) we output that as well.
