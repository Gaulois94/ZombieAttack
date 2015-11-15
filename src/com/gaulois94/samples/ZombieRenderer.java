package com.gaulois94.samples;

import com.gaulois94.Graphics.Renderer;
import android.view.Surface;
import android.content.Context;

public class ZombieRenderer extends Renderer
{
	public ZombieRenderer(Context c)
	{
		super(c);
	}

	public long createPtr(long parent, Surface surface)
	{
		return createZombieRenderer(parent, surface);
	}

	static private native long createZombieRenderer(long parent, Surface surface);
}
