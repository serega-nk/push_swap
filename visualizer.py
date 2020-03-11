# import basic pygame modules
import pygame
from pygame.locals import *

# constants
SCREENRECT = Rect(0, 0, 1024, 768)

import random

def draw_text_middle(surface, text, size, color):
    font = pygame.font.SysFont("arial", size, bold=True)
    label = font.render(text, 1, color)

    surface.blit(label, SCREENRECT.center);


def main():
    pygame.init()

    fullscreen = False
    screen = pygame.display.set_mode(SCREENRECT.size)
    # icon = pygame.transform.scale(Alien.images[0], (32, 32))
    # pygame.display.set_icon(icon)
    pygame.display.set_caption('PUSH_SWAP!')
    
    clock = pygame.time.Clock()

    running = True
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT or \
                (event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE):
                running = False
            elif event.type == pygame.KEYDOWN and event.key == pygame.K_f: 
                fullscreen = not fullscreen

        if fullscreen:
            color = (random.randrange(255), random.randrange(255), random.randrange(255))
        else:
            color = (0, 0, 0)
    
    

        
        screen.fill(color)
        #draw_text_middle(screen, 'Press Any Key To Play', 60, (255,255,255))
        pygame.draw.rect(screen, (255, 0, 0), (100, 100, 200, 200), 5)
        pygame.display.update()

        # cap the framerate
        clock.tick(10000)

    pygame.quit()

# call the "main" function if running this script
if __name__ == '__main__': main()
