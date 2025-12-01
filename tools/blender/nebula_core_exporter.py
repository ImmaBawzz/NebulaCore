bl_info = {
    "name": "NebulaCore Exporter",
    "author": "Nebula Team",
    "version": (0, 1, 0),
    "blender": (4, 0, 0),
    "location": "File > Export > NebulaCore Scene",
    "category": "Import-Export",
}

import bpy
from bpy_extras.io_utils import ExportHelper
from bpy.types import Operator
from bpy.props import StringProperty

class ExportNebulaCore(Operator, ExportHelper):
    bl_idname = "export_scene.nebula_core"
    bl_label = "Export NebulaCore Scene"
    filename_ext = ".nebula"

    filter_glob: StringProperty(
        default="*.nebula",
        options={'HIDDEN'},
        maxlen=255,
    )

    def execute(self, context):
        # TODO: Walk through scene graph, meshes, materials, etc.
        # and write a .nebula or .json/.gltf file
        self.report({'INFO'}, "Exporting to " + self.filepath)
        return {'FINISHED'}

def menu_func_export(self, context):
    self.layout.operator(ExportNebulaCore.bl_idname, text="NebulaCore Scene (.nebula)")

def register():
    bpy.utils.register_class(ExportNebulaCore)
    bpy.types.TOPBAR_MT_file_export.append(menu_func_export)

def unregister():
    bpy.utils.unregister_class(ExportNebulaCore)
    bpy.types.TOPBAR_MT_file_export.remove(menu_func_export)

if __name__ == "__main__":
    register()
