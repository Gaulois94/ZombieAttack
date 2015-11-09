package com.gaulois94.samples;
import com.gaulois94.Graphics.Renderer;

public class ZombieRenderer extends Renderer
{
	public ZombieRenderer(Context context)
	{
		super(context);
	}

	public long createPtr(long parent, Surface surface)
	{
		return initZombieRenderer(parent, surface);
	}

	static private native long createZombieRenderer(long parent, Surface surface);
}
