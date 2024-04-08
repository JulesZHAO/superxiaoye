import os

from moviepy.editor import VideoFileClip
from moviepy.editor import TextClip
from moviepy.editor import CompositeVideoClip
from moviepy.video.io.ffmpeg_tools import ffmpeg_extract_subclip
from scenedetect.video_manager import VideoManager
from scenedetect.scene_manager import SceneManager
from scenedetect.stats_manager import StatsManager
from scenedetect.detectors.content_detector import ContentDetector
import moviepy.editor as mpy



def find_scenes(video_path):
    video_manager = VideoManager([video_path])                           # 创建视频管理器
    stats_manager = StatsManager()                                       # 创建统计管理器
    scene_manager = SceneManager(stats_manager)                          # 创建场景管理器
    scene_manager.add_detector(ContentDetector(threshold=30))            # 添加内容检测器
    
    try:
        
        video_manager.set_downscale_factor()                            # 设置下采样因子
        video_manager.start()                                           # 开始读取视频
        scene_manager.detect_scenes(frame_source=video_manager)         # 检测场景

        scene_list = scene_manager.get_scene_list()                     # 获取场景列表
        print('List of scenes obtained:')
        for i, scene in enumerate(scene_list):
            output_file = f'video_{i + 1}.mp4'                          # 输出文件名
            print(f'video_{i + 1}.mp4')
           
            start_time = scene[0].get_frames() / video_manager.get_framerate() # 计算起始和结束时间（以秒为单位）
            end_time = scene[1].get_frames() / video_manager.get_framerate()
           
            output_file = f'video_{i + 1}.mp4' # 输出文件名
           
            ffmpeg_extract_subclip(video_path, start_time, end_time, targetname=output_file) # 使用ffmpeg提取子剪辑

    finally:
        
        video_manager.release()                                         # 释放视频资源

if __name__ == '__main__':
    find_scenes('operator.mp4')
