struct vertexIn
{
	float4		  pos: POSITION;
	unsigned int2 uv : TEXCOORD;
};

struct vertexOut
{
	float4		 pos	: SV_POSITION;
	float2		 uv		: TEXCOORD0;
};


Texture2D		txDiffuse	: register( t0 );
SamplerState	samLinear	: register( s0 );

//�O���[�o��
cbuffer global
{
	float4 size;
	float4 color;
	float4 rect_in;
	float4 rect_out;
};

//���_�V�F�[�_
vertexOut vs(vertexIn IN)
{
	vertexOut OUT;
	
	//�\��t���ʒu�s��
	float4x4 mat={
		((rect_out.z-rect_out.x)/size.z)*2.0f,									   0.0f,		0.0f,		0.0f,
								  0.0f,			 (-(rect_out.w-rect_out.y)/size.w)*2.0f,		0.0f,		0.0f,
								  0.0f,											   0.0f,		1.0f,		0.0f,
		 (rect_out.x*2.0f)/size.z-1.0f,					  (-rect_out.y*2.0f)/size.w+1.0,		0.0f,		1.0f,
	};

	//��]�p�s��
	float4x4 tmat={
		1.0f, 0.0f,0.0f,0.0f,
		0.0f, 1.0f,0.0f,0.0f,
		0.0f, 0.0f,1.0f,0.0f,
	   -0.5f,-0.5f,0.0f,1.0f,
	};
	float4x4 rmat={
		cos(3.14f/180.0f*size.y),	-sin(3.14f/180.0f*size.y),0.0f,0.0f,
		sin(3.14f/180.0f*size.y),	 cos(3.14f/180.0f*size.y),0.0f,0.0f,
						    0.0f,						 0.0f,1.0f,0.0f,
							0.5f,					     0.5f,0.0f,1.0f,
	};

	//2D�ϊ��s��*��]�s��
	float4x4 outmat=mul(mul(tmat,rmat),mat);

	float f[4]= { rect_in.x/size.x , rect_in.z/size.x , rect_in.y /size.x , rect_in.w/size.x };
	float2 uv=(float2)0.0f;
	uv.x=f[IN.uv.x];
	uv.y=f[IN.uv.y];
	
	
	OUT.pos = mul(IN.pos,outmat);
	OUT.uv  = uv;
	return OUT;
}

//�s�N�Z���V�F�[�_
float4 ps(vertexOut IN) : SV_Target
{
	float4  col=(float4)0.0f;
	float4  tex=(float4)0.0f;

	//�e�N�X�`���T�C�Y��񂪑��݂��Ȃ��ꍇ�@�J���[���݂̂ƔF������
	if(size.x==0.0f)
	{
		col = color;//�J���[�I����
	}
	else
	{
		tex = txDiffuse.Sample(samLinear, IN.uv);//�e�N�X�`��
		col = tex*color;					     //�J���[����
	}


	
	return col;
}