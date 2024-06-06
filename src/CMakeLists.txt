# CMakeList.txt : CMake project for ex3, include source and define
# project specific logic here.
#

# Add source to this project's executable.
target_sources (adventureIsalnd_project PRIVATE "main.cpp"
                                      "Controller.cpp"
                                      "Game.cpp"
                                      "Board.cpp"
                                      "Block.cpp"
                                      "Bonus.cpp"
                                      "BonusApple.cpp"
                                      "BonusPineApple.cpp"
                                      "BonusTomato.cpp"
                                      "BonusBanana.cpp"
                                      "BonusAxe.cpp"
                                      "BonusFire.cpp"
                                      "BonusSkateBoard.cpp"
                                      "Player.cpp"
                                      "Egg.cpp"
                                      "Weapon.cpp"
                                      "WeaponAxe.cpp"
                                      "WeaponFire.cpp"
                                      "Enemy.cpp"
                                      "Object.cpp"
                                      "IdleObject.cpp"
                                      "MovingObject.cpp"
                                      "Sound.cpp"
                                      "Sprite.cpp"
                                      "AnimatedSprite.cpp"
                                      "AudioController.cpp"
                                      "MainMenu.cpp"
                                      "Bird.cpp"
                                      "Frog.cpp"
                                      "Snail.cpp"
                                      "FireWood.cpp"
                                      "Trampoline.cpp")

# TODO: Add tests and install targets if needed.
