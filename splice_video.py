# -*- coding: GB2312 -*-

import os

from moviepy.editor import concatenate_videoclips
from moviepy.editor import VideoFileClip

def merge_selected_scenes(selected_scenes):
    
    video_clips = []                                                            # ���ڴ洢��ƵƬ�ε��б�
    file_names = sorted(os.listdir())                                           # ��ȡ��ǰĿ¼�µ������ļ���
    
    for file_name in file_names:                                                # �����ļ����б�
        if file_name.endswith('.mp4') and file_name.startswith('video'):        # ����ļ�����'.mp4'��β����'video'��ͷ 
            scene_number = int(file_name.split('_')[1].split('.')[0])           # ��ȡ�������
            if scene_number in selected_scenes:                                 # ������������ѡ�еĳ����б���
                video_clip = VideoFileClip(file_name)                           # ������ƵƬ�ζ���
                video_clips.append(video_clip)                                  # ����ƵƬ����ӵ��б���

    final_video = concatenate_videoclips(video_clips)                           # �ϲ���ƵƬ��
   
    final_video.write_videofile('merged_scenes.mp4', codec='libx264')           # ���ϲ������Ƶд���ļ�

selected_scenes_input = input("input the selected scenesd, split by ','")
selected_scenes = [int(scene) for scene in selected_scenes_input.split(',')]

merge_selected_scenes(selected_scenes)
