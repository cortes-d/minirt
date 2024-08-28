import os
import subprocess

def run_scenes_concurrently(n):
    # Directory containing the scene files
    scene_dir = "test_scenes"
    
    processes = []

    # Loop through each scene file from 1.rt to n.rt
    for i in range(1, n + 1):
        scene_file = f"{i}.rt"
        scene_path = os.path.join(scene_dir, scene_file)
        
        # Check if the scene file exists
        if os.path.isfile(scene_path):
            print(f"Launching scene: {scene_file}")
            # Launch the ./minirt program with the scene file as argument
            process = subprocess.Popen(["./minirt", scene_path])
            processes.append(process)
        else:
            print(f"Scene file {scene_file} not found in {scene_dir}")

    # Wait for all processes to complete
    for process in processes:
        process.wait()

if __name__ == "__main__":
    # Set the number of scenes
    number_of_scenes = 8  # Change this number to the total number of scenes
    run_scenes_concurrently(number_of_scenes)
