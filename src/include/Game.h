#ifndef CLASS_GAME_H
#define CLASS_GAME_H

#include "Globals.h"
#include "Scene.h"
#include "SceneManager.h"

/**
 * Core class for any game.
 */

class Game
{
  public:
    /**
     * Returns single instance of Game.
     * @return Unique instance of Game in whole program.
     */
    static Game& getInstance()
    {
      static Game instance;
      return instance;
    }
    /**
     * Render the active scene.
     */
    void render();
    /**
     * Update the active scene.
     * @param dt milliseconds passed from last call.
     */
    void update(float);
    /**
     * Initialize the gmae.
     */
    void init();
    /**
     * Returns scene manager
     * @see sm
     * @see SceneManager
     * @return Pointer to scene manager.
     */
    SceneManager* getSceneManager();
  private:
    Game();
    Game(Game const&);
    void operator=(Game const&);
    ~Game();
    /**
     * Handles all scenes aspects.
     */
    SceneManager *sm;
};
#endif
