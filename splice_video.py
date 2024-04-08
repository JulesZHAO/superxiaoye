# -*- coding: GB2312 -*-

import os

from moviepy.editor import concatenate_videoclips
from moviepy.editor import VideoFileClip

def merge_selected_scenes(selected_scenes):
    
    video_clips = []                                                            # 用于存储视频片段的列表
    file_names = sorted(os.listdir())                                           # 获取当前目录下的所有文件名
    
    for file_name in file_names:                                                # 遍历文件名列表
        if file_name.endswith('.mp4') and file_name.startswith('video'):        # 如果文件名以'.mp4'结尾且以'video'开头 
            scene_number = int(file_name.split('_')[1].split('.')[0])           # 获取场景编号
            if scene_number in selected_scenes:                                 # 如果场景编号在选中的场景列表中
                video_clip = VideoFileClip(file_name)                           # 创建视频片段对象
                video_clips.append(video_clip)                                  # 将视频片段添加到列表中

    final_video = concatenate_videoclips(video_clips)                           # 合并视频片段
   
    final_video.write_videofile('merged_scenes.mp4', codec='libx264')           # 将合并后的视频写入文件

selected_scenes_input = input("input the selected scenesd, split by ','")
selected_scenes = [int(scene) for scene in selected_scenes_input.split(',')]

merge_selected_scenes(selected_scenes)
