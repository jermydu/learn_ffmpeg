/**
 * 雷霄骅ffmpeg博客教程的学习代码记录
 */

#include <iostream>

extern int simplest_yuv420_split(const char* url, int w, int h, int num);
extern int simplest_yuv444_split(const char* url, int w, int h, int num);

int main()
{
	simplest_yuv420_split("../../dujinwei_ffmpeg_learn/test/lena_256x256_yuv420p.yuv",256,256,1);
	simplest_yuv444_split("../../dujinwei_ffmpeg_learn/test/lena_256x256_yuv444p.yuv",256,256,1);
}

/**
  * 将YUV420P数据中的Y、U、V三个分量分离开来并保存成三个文件
  * @param url  Location of Input YUV file.
  * @param w    Width of Input YUV file.
  * @param h    Height of Input YUV file.
  * @param num  Number of frames to process.
  *
  */
int simplest_yuv420_split(const char* url, int w, int h, int num) 
{
	FILE* fp, *fp1, *fp2, *fp3;
	fopen_s(&fp,url, "rb+");
	fopen_s(&fp1, "../../dujinwei_ffmpeg_learn/test/output_lena_256x256_yuv420p_y.y", "wb+");
	fopen_s(&fp2, "../../dujinwei_ffmpeg_learn/test/output_lena_256x256_yuv420p_u.y", "wb+");
	fopen_s(&fp3, "../../dujinwei_ffmpeg_learn/test/output_lena_256x256_yuv420p_v.y", "wb+");

	unsigned char* pic = (unsigned char*)malloc(w * h * 3 / 2);

	for (int i = 0; i < num; i++) {

		if (fp)
		{
			fread(pic, 1, w * h * 3 / 2, fp);
		}
		if (fp1 && pic)
		{
			//Y
			fwrite(pic, 1, w * h, fp1);
		}
		if (fp2 && pic)
		{
			//U
			fwrite(pic + w * h, 1, w * h / 4, fp2);
		}
		if (fp3 && pic)
		{
			//V
			fwrite(pic + w * h * 5 / 4, 1, w * h / 4, fp3);
		}
	}

	if (pic)
	{
		free(pic);
	}
	if (fp)
	{
		fclose(fp);
	}
	if (fp1)
	{
		fclose(fp1);
	}
	if (fp2)
	{
		fclose(fp2);
	}
	if (fp3)
	{
		fclose(fp3);
	}

	return 0;
}

/**
 * YUV444P数据中的Y、U、V三个分量分离开来并保存成三个文件
 * @param url  Location of YUV file.
 * @param w    Width of Input YUV file.
 * @param h    Height of Input YUV file.
 * @param num  Number of frames to process.
 *
 */
int simplest_yuv444_split(const char* url, int w, int h, int num) 
{
	FILE* fp, * fp1, * fp2, * fp3;
	fopen_s(&fp, url, "rb+");
	fopen_s(&fp1, "../../dujinwei_ffmpeg_learn/test/output_lena_256x256_yuv444p_y.y", "wb+");
	fopen_s(&fp2, "../../dujinwei_ffmpeg_learn/test/output_lena_256x256_yuv444p_u.y", "wb+");
	fopen_s(&fp3, "../../dujinwei_ffmpeg_learn/test/output_lena_256x256_yuv444p_v.y", "wb+");
	unsigned char* pic = (unsigned char*)malloc(w * h * 3);

	for (int i = 0; i < num; i++) {
		if (fp)
		{
			fread(pic, 1, w * h * 3, fp);
		}
		if (fp1 && pic)
		{
			//Y
			fwrite(pic, 1, w * h, fp1);
		}
		if (fp2 && pic)
		{
			//U
			fwrite(pic + w * h, 1, w * h, fp2);
		}
		if (fp3 && pic)
		{
			//V
			fwrite(pic + w * h * 2, 1, w * h, fp3);
		}
	}

	if (pic)
	{
		free(pic);
	}
	if (fp)
	{
		fclose(fp);
	}
	if (fp1)
	{
		fclose(fp1);
	}
	if (fp2)
	{
		fclose(fp2);
	}
	if (fp3)
	{
		fclose(fp3);
	}

	return 0;
}