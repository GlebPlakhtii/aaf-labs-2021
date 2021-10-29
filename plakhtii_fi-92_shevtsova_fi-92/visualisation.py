from R_Tree_To_compile.R_Tree import *
import pygame as pg
import random
import colorsys

t = R_Tree()



def draw_tree(t: R_Tree):
    s = t.to_string()

    ls = s.split('\n')[:-1]
    nodes = [{"level": int(i.split()[0]), "rect": [float(i.split()[1].replace('((','').replace(',','')),float(i.split()[2].replace('(','').replace(')','').replace(',','')),
                                              float(i.split()[3].replace('(','').replace(',','')),float(i.split()[4].replace('(','').replace(')','').replace(',','')) ]} for i in ls]
    l = max(10,nodes[-1]['level'])
    max_level = nodes[-1]['level']
    nodes = sorted(nodes, key=lambda a: a['level'])
    indent = 0
    border = 1
    for node in nodes:
        pg.draw.rect(screen,[j*255 for j in colorsys.hsv_to_rgb((max_level - node['level'])/(l*1.1), 1, 1)],(node['rect'][0]+node['level']*indent + border,node['rect'][1]+node['level']*indent + border,node['rect'][2]-node['rect'][0]-node['level']*2*indent - border*2,node['rect'][3] - node['rect'][1]-node['level']*2*indent - border*2),border_radius=4)
    for node in nodes:
        pg.draw.rect(screen, (0, 0, 0), (node['rect'][0] + node['level'] * indent, node['rect'][1] + node['level'] * indent,
                                     node['rect'][2] - node['rect'][0] - node['level'] * 2 * indent,
                                     node['rect'][3] - node['rect'][1] - node['level'] * 2 * indent), border, border_radius=4)

def insert(t,ps,pf):
    t.insert(Rect(min(ps[0],pf[0]),min(ps[1],pf[1]),max(ps[0],pf[0]),max(ps[1],pf[1])))


WIDTH = 1500
HEIGHT = 1000
FPS = 30

pg.init()
pg.mixer.init()
screen = pg.display.set_mode((WIDTH, HEIGHT))
pg.display.set_caption("R-Tree")
clock = pg.time.Clock()


running = True

start_pos = 0
while running:

    clock.tick(FPS)




    for event in pg.event.get():
        if event.type == pg.QUIT:
            running = False
        if event.type == pg.MOUSEBUTTONDOWN:
            if pg.mouse.get_pressed()[0]:
                if not start_pos:
                    start_pos = pg.mouse.get_pos()
                else:
                    insert(t,start_pos, pg.mouse.get_pos())
                    start_pos = 0









    screen.fill((150,150,150))
    draw_tree(t)



    pg.display.flip()

pg.quit()






