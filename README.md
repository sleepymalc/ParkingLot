# Parking Lot

<p align="center"><b><i>
	Start Parking! 🚗 Watch Out! ⚠️
</i></b></p>

## Parking Lot Manager

- Input: The parking lot's total floor number, and the total time of this program.
- Output: two types of tickets: one is an arrival ticket, another is a departure ticket.
- ​Parking lot set up: For only one floor, there will have equally four types of slots for each type of vehicle, and if there is more than one floor, the first floor will always be divided into two parts, one is for bicycles, another is for motorbike. And for a higher floor, each floor will also be divided into two parts, one is for vans, another is for cars.

## Parking Lot

### Abstract

Instead of making a boring animation, we make it into a game features with

​1. Lovely drawing of UFO and rocket, etc.
2. Teleport can transform into polygons with a different number of sides and change color during the transformation.
3. To make it more fun, we make it an interactive game, see the [game rules](#game-rules) below.

### Game Rules

The player will control a rocket, which appears in a random teleport at the beginning, and your goal is to destroy all the vehicles before they all have parking.

In detail,

1. Your initial position is at a random teleport.
2. If more than three vehicles are parked successfully, you lose.
3. If your rocket bumps into another vehicle, it will collapse and you lose.
4. You can only leave less than three vehicles parked successfully, or you lose.

### Control

- Move: `w` (up), `a` (turn left), `s` (down), `d` (turn right).
- Shoot: `space` (to shoot a laser with delay)

### Implementation Detail

1. Our Rocket doesn't zoom in and out, instead, we zoom in and out of the flames to make it more real.
2. Our car is replaced with a cute cart, and the flag is replaced with a windmill.

## About Honor Code

According to the SJTU student handbook (2019 version),

> It is a violation of the Honor Code for students to submit, as their own, work that is not the result of their own labor and thoughts. This applies, in particular, to ideas, expressions or work obtained from other students as well as from books, the internet, and other sources. The failure to properly credit ideas, expressions or work from others is considered plagiarism.

## Contribution

<p align="center"><b><i>
	Yuyang Chen, Pingbang Hu
</i></b></p>

---

The works are partially contributed by some other students, TAs, and professors, which would be listed if known.
> If you find any problems in the repository, welcome to make an issue or pull request.
