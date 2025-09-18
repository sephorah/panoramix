# Panoramix

## Context

The year is 50 BC. Gaul is entirely occupied by the Romans. Well, not entirely../ One small village of indomitable Gauls still holds out against the invaders. And life is not easy for the Roman legionaries who garrison the fortified camps of Totorum, Aquarium, Laudanum and Compendium... In this village the druid prepares a cooking pot of magic potions. The villagers get a serving of potion and then procede to beat roman soldiers. When the pot is empty, the villager wakes up the druid and waits until the druid has refilled the pot.

The purpose of this project is to study examples of threads and mutex programming and the algorithmic difficulties that go with it.

## Getting started

Build the project.
```
make
```

```
USAGE: ./panoramix <nb_villagers> <pot_size> <nb_fights> <nb_refills>
```

- nb_villagers: indicates the number of villagers;
- pot_size: indicates the maximum number that can be contained in the cooking pot;
- nb_fights: indicates the maximum number of fights a villager will engage in;
- nb_refills: incicates the maximum number of time the druid will refill the pot.

All values must be >0.

Example:

```
./panoramix 3 5 3 1
Villager 0: Going into battle!
Villager 0: I need a drink... I see 5 servings left.
Villager 0: Take that roman scum! Only 2 left.
Villager 0: I need a drink... I see 4 servings left.
Villager 0: Take that roman scum! Only 1 left.
Villager 0: I need a drink... I see 3 servings left.
Villager 0: Take that roman scum! Only 0 left.
Villager 0: I'm going to sleep now.
Druid: I'm ready... but sleepy...
Villager 2: Going into battle!
Villager 2: I need a drink... I see 2 servings left.
Villager 2: Take that roman scum! Only 2 left.
Villager 2: I need a drink... I see 1 servings left.
Villager 2: Take that roman scum! Only 1 left.
Villager 2: I need a drink... I see 0 servings left.
Villager 2: Hey Pano wake up! We need more potion.
Villager 1: Going into battle!
Villager 1: I need a drink... I see 0 servings left.
Druid: Ah! Yes, yes, I'm awake! Working on it! Beware I can only make 0 more refills after this one.
Druid: I'm out of viscum. I'm going back to... zZz
Villager 1: Take that roman scum! Only 2 left.
Villager 1: I need a drink... I see 4 servings left.
Villager 1: Take that roman scum! Only 1 left.
Villager 1: I need a drink... I see 3 servings left.
Villager 1: Take that roman scum! Only 0 left.
Villager 1: I'm going to sleep now.
Villager 2: Take that roman scum! Only 0 left.
Villager 2: I'm going to sleep now.
```

