# 204ducks
A program that compute chances that a duck come back after t minutes by the following probabiliy density function:

<p align="center">
    <img src="https://cdn.discordapp.com/attachments/452262356823834625/617123640856805388/unknown.png" alt="Logo" width="500" height="100"/>
</p>

**Usage** <br>
```bash
./204ducks a

    a: constant between 0 and 2.5
```

**Output** <br>
```bash
./204ducks 1.6
Average return time: 1m 21s
Standard deviation: 1.074
Time after which 50% of the ducks are back: 1m 04s
Time after which 99% of the ducks are back: 5m 04s
Percentage of ducks back after 1minute: 46.9%
Percentage of ducks back after 2minutes: 79.1%
```
```bash
./204ducks 0.2
Average return time: 0m 50s
Standard deviation: 0.676
Time after which 50% of the ducks are back: 0m 39s
Time after which 99% of the ducks are back: 3m 16s
Percentage of ducks back after 1minute: 71.3%
Percentage of ducks back after 2minutes: 94.2%
```