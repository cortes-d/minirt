import os
import subprocess

def run_scenes_concurrently():
    # Directory containing the scene files
    scene_dir = "test_scenes"
    
    processes = []

    # Get all files in the scene directory
    scene_files = [f for f in os.listdir(scene_dir) if os.path.isfile(os.path.join(scene_dir, f))]

    # Loop through each scene file
    for scene_file in scene_files:
        scene_path = os.path.join(scene_dir, scene_file)
        
        print(f"Launching scene: {scene_file}")
        # Launch the ./minirt program with the scene file as argument
        process = subprocess.Popen(["./minirt", scene_path])
        processes.append(process)

    # Wait for all processes to complete
    for process in processes:
        process.wait()

if __name__ == "__main__":
    run_scenes_concurrently()