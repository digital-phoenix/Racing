
import bpy
import os
import sys

out=open( os.path.splitext( bpy.data.filepath )[0] + '.ogl' , "w") 

verts=""
faces=""

for obj in bpy.data.objects:
    
    
    obj.select = True
    
    nverts = 0
    nfaces = 0
    bpy.ops.object.mode_set( mode = 'EDIT')
    bpy.ops.mesh.select_all(action='SELECT') 
    bpy.ops.mesh.quads_convert_to_tris()
    
    bpy.ops.object.editmode_toggle()
    

    
    for v in obj.data.vertices:
        verts = verts + "v "
        nverts = nverts + 1
        for i in v.co:
            verts = verts + str(i) + " " 
        verts = verts + '\n'
    

    for face in obj.data.faces:
        
        faces = faces + "f "
        nfaces= nfaces + 1
        
        for n in face.normal:
            faces= faces + str(n) + " "
        for v in face.vertices:
            
            faces= faces + str(v) + " "

        
            
        faces = faces + "\n"

out.write( str(nverts) + " " + str( nfaces ) + "\n" + verts + faces)

out.close()