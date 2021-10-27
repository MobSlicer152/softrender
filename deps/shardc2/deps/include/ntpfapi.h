/*
 * Process Hacker -
 *   Prefetcher (Superfetch) support functions
 *
 * This file is part of Process Hacker.
 *
 * Process Hacker is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Process Hacker is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Process Hacker.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _NTPFAPI_H
#define _NTPFAPI_H

// begin_private

// Prefetch

typedef enum _PF_BOOT_PHASE_ID
{
    PfKernelInitPhase = 0,
    PfBootDriverInitPhase = 90,
    PfSystemDriverInitPhase = 120,
    PfSessionManagerInitPhase = 150,
    PfSMRegistryInitPhase = 180,
    PfVideoInitPhase = 210,
    PfPostVideoInitPhase = 240,
    PfBootAcceptedRegistryInitPhase = 270,
    PfUserShellReadyPhase = 300,
    PfMaxBootPhaseId = 900
} PF_BOOT_PHASE_ID;

typedef enum _PF_ENABLE_STATUS
{
    PfSvNotSpecified,
    PfSvEnabled,
    PfSvDisabled,
    PfSvMaxEnableStatus
} PF_ENABLE_STATUS;

typedef struct _PF_TRACE_LIMITS
{
    ULONG MaxNumPages;
    ULONG MaxNumSections;
    LONGLONG TimerPeriod;
} PF_TRACE_LIMITS, *PPF_TRACE_LIMITS;

typedef struct _PF_SYSTEM_PREFETCH_PARAMETERS
{
    PF_ENABLE_STATUS EnableStatus[2];
    PF_TRACE_LIMITS TraceLimits[2];
    ULONG MaxNumActiveTraces;
    ULONG MaxNumSavedTraces;
    WCHAR RootDirPath[32];
    WCHAR HostingApplicationList[128];
} PF_SYSTEM_PREFETCH_PARAMETERS, *PPF_SYSTEM_PREFETCH_PARAMETERS;

#define PF_BOOT_CONTROL_VERSION 1

typedef struct _PF_BOOT_CONTROL
{
    ULONG Version;
    ULONG DisableBootPrefetching;
} PF_BOOT_CONTROL, *PPF_BOOT_CONTROL;

typedef enum _PREFETCHER_INFORMATION_CLASS
{
    PrefetcherRetrieveTrace = 1, // q: CHAR[]
    PrefetcherSystemParameters, // q: PF_SYSTEM_PREFETCH_PARAMETERS
    PrefetcherBootPhase, // s: PF_BOOT_PHASE_ID
    PrefetcherSpare1, // PrefetcherRetrieveBootLoaderTrace // q: CHAR[]
    PrefetcherBootControl, // s: PF_BOOT_CONTROL
    PrefetcherScenarioPolicyControl,
    PrefetcherSpare2,
    PrefetcherAppLaunchScenarioControl,
    PrefetcherInformationMax
} PREFETCHER_INFORMATION_CLASS;

#define PREFETCHER_INFORMATION_VERSION 23 // rev
#define PREFETCHER_INFORMATION_MAGIC ('kuhC') // rev

typedef struct _PREFETCHER_INFORMATION
{
    _In_ ULONG Version;
    _In_ ULONG Magic;
    _In_ PREFETCHER_INFORMATION_CLASS PrefetcherInformationClass;
    _Inout_ PVOID PrefetcherInformation;
    _Inout_ ULONG PrefetcherInformationLength;
} PREFETCHER_INFORMATION, *PPREFETCHER_INFORMATION;

// Superfetch

typedef struct _PF_SYSTEM_SUPERFETCH_PARAMETERS
{
    ULONG EnabledComponents;
    ULONG BootID;
    ULONG SavedSectInfoTracesMax;
    ULONG SavedPageAccessTracesMax;
    ULONG ScenarioPrefetchTimeoutStandby;
    ULONG ScenarioPrefetchTimeoutHibernate;
    ULONG ScenarioPrefetchTimeoutHiberBoot;
} PF_SYSTEM_SUPERFETCH_PARAMETERS, *PPF_SYSTEM_SUPERFETCH_PARAMETERS;

#define PF_PFN_PRIO_REQUEST_VERSION 1
#define PF_PFN_PRIO_REQUEST_QUERY_MEMORY_LIST 0x1
#define PF_PFN_PRIO_REQUEST_VALID_FLAGS 0x1

typedef struct _PF_PFN_PRIO_REQUEST
{
    ULONG Version;
    ULONG RequestFlags;
    ULONG_PTR PfnCount;
    SYSTEM_MEMORY_LIST_INFORMATION MemInfo;
    MMPFN_IDENTITY PageData[256];
} PF_PFN_PRIO_REQUEST, *PPF_PFN_PRIO_REQUEST;

typedef enum _PFS_PRIVATE_PAGE_SOURCE_TYPE
{
    PfsPrivateSourceKernel,
    PfsPrivateSourceSession,
    PfsPrivateSourceProcess,
    PfsPrivateSourceMax
} PFS_PRIVATE_PAGE_SOURCE_TYPE;

typedef struct _PFS_PRIVATE_PAGE_SOURCE
{
    PFS_PRIVATE_PAGE_SOURCE_TYPE Type;
    union
    {
        ULONG SessionId;
        ULONG ProcessId;
    };
    ULONG ImagePathHash;
    ULONG_PTR UniqueProcessHash;
} PFS_PRIVATE_PAGE_SOURCE, *PPFS_PRIVATE_PAGE_SOURCE;

typedef struct _PF_PRIVSOURform_feedback

#define MC_GL_EXT_packed_pixels

#define MC_WGL_ARB_pbuffer

#define MC_GL_ARB_explicit_attrib_location

#define MC_GL_EXT_texture_sRGB

#define gl_FragData iris_FragData
#define varying in
#define gl_ModelViewProjectionMatrix (gl_ProjectionMatrix * gl_ModelViewMatrix)
#define gl_ModelViewMatrix (iris_ModelViewMat * _iris_internal_translate(iris_ChunkOffset))
#define gl_NormalMatrix mat3(transpose(inverse(gl_ModelViewMatrix)))
#define gl_Color (Color * iris_ColorModulator)
#define gl_ProjectionMatrix iris_ProjMat
#define gl_FogFragCoord iris_FogFragCoord
#define MC_RENDER_QUALITY 1.0
#define MC_SHADOW_QUALITY 1.0

#extension GL_ARB_shader_texture_lod : enable

#define GBUFFERS_ENTITIES
#define OVERWORLD
#define FSH

uniform mat4 iris_LightmapTextureMatrix;
uniform mat4 iris_TextureMat;
uniform float iris_FogDensity;
uniform float iris_FogStart;
uniform float iris_FogEnd;
uniform vec4 iris_FogColor;

struct iris_FogParameters {
    vec4 color;
    float density;
    float start;
    float end;
    float scale;
};

iris_FogParameters iris_Fog = iris_FogParameters(iris_FogColor, iris_FogDensity, iris_FogStart, iris_FogEnd, 1.0 / (iris_FogEnd - iris_FogStart));

#define gl_Fog iris_Fog
in float iris_FogFragCoord;
uniform mat4 iris_ProjMat;
uniform vec4 iris_ColorModulator;
uniform mat4 iris_ModelViewMat;
uniform vec3 iris_ChunkOffset;
mat4 _iris_internal_translate(vec3 offset) {
    // NB: Column-major order
    return mat4(1.0, 0.0, 0.0, 0.0,
                0.0, 1.0, 0.0, 0.0,
                0.0, 0.0, 1.0, 0.0,
                offset.x, offset.y, offset.z, 1.0);
}
out vec4 iris_FragData[8];
vec4 texture2D(sampler2D sampler, vec2 coord) { return texture(sampler, coord); }
vec4 texture2D(sampler2D sampler, vec2 coord, float bias) { return texture(sampler, coord, bias); }
vec4 texture2DLod(sampler2D sampler, vec2 coord, float lod) { return textureLod(sampler, coord, lod); }
vec4 shadow2D(sampler2DShadow sampler, vec3 coord) { return vec4(texture(sampler, coord)); }
vec4 shadow2DLod(sampler2DShadow sampler, vec3 coord, float lod) { return vec4(textureLod(sampler, coord, lod)); }
/*
Complementary Shaders by EminGT, based on BSL Shaders by Capt Tatsu
*/

//Common//
/*
Complementary Shaders by EminGT, based on BSL Shaders by Capt Tatsu
*/

/*--------------------------------------------------------------------
         ___ __  __ ____   ___  ____ _____  _    _   _ _____ 
        |_ _|  \/  |  _ \ / _ \|  _ \_   _|/ \  | \ | |_   _|
         | || |\/| | |_) | | | | |_) || | / _ \ |  \| | | |  
         | || |  | |  __/| |_| |  _ < | |/ ___ \| |\  | | |  
        |___|_|  |_|_|    \___/|_| \_\|_/_/   \_\_| \_| |_|  
         .
  -> -> -> EDITING THIS FILE HAS A HIGH CHANCE TO BREAK COMPLEMENTARY
  -> -> -> DO NOT CHANGE ANYTHING UNLESS YOU KNOW WHAT YOU ARE DOING
  -> -> -> DO NOT EXPECT SUPPORT AFTER MODIFYING SHADER FILES
--------------------------------------------------------------------*/

//Shader Options//

//#define COMPATIBILITY_MODE
  #define RP_SUPPORT 1 //[1 2 3 4]
  #define SECRET 0 //[0]

//#define TEST
  #define GLOWING_ENTITY_FIX
  #define END_PORTAL_REWORK
  #define LIGHTNING_BOLTS_FIX
//#define NIGHT_TWILIGHT_FOREST
  #define LIGHT_LEAK_FIX
  #define ENTITY_NORMAL_FIX
  #define THE_FORBIDDEN_OPTION 0 //[0 1 2 3]
  #define WRONG_MIPMAP_FIX
  #define FLICKERING_FIX
  #define SKY_REF_FIX_1 2 //[1 2 3]
  #define OVERLAY_FIX
  #define CAVE_SKY_FIX
//#define SMOKEY_WATER_LIGHTSHAFTS
//#define MIN_LIGHT_EVERYWHERE
//#define METALLIC_WORLD
//#define ANAMORPHIC_BLOOM
//#define EXTRA_PARTICLE_EMISSION
//#define WAVING_EVERYTHING
//#define GBUFFER_CODING
//#define SHOW_RAY_TRACING
//#define RANDOM_BLOCKLIGHT
//#define OVERDRAW
  #define RAIN_REF_BIOME_CHECK
//#define RAIN_REF_FORCED

  #define WAVING_SPEED 1.00 //[0.01 0.02 0.03 0.04 0.05 0.06 0.07 0.08 0.09 0.10 0.12 0.15 0.20 0.25 0.30 0.35 0.40 0.45 0.50 0.55 0.60 0.65 0.70 0.75 0.80 0.85 0.90 0.95 1.00 1.05 1.10 1.15 1.20 1.25 1.30 1.35 1.40 1.45 1.50 1.55 1.60 1.65 1.70 1.75 1.80 1.85 1.90 1.95 2.00 2.10 2.20 2.30 2.40 2.50 2.60 2.70 2.80 2.90 3.00 3.50 4.00 4.50 5.00]
  #define WAVING_INTENSITY 1.00 //[0.01 0.02 0.03 0.04 0.05 0.06 0.07 0.08 0.09 0.10 0.12 0.15 0.20 0.25 0.30 0.35 0.40 0.45 0.50 0.55 0.60 0.65 0.70 0.75 0.80 0.85 0.90 0.95 1.00 1.05 1.10 1.15 1.20 1.25 1.30 1.35 1.40 1.45 1.50 1.55 1.60 1.65 1.70 1.75 1.80 1.85 1.90 1.95 2.00 2.10 2.20 2.30 2.40 2.50 2.60 2.70 2.80 2.90 3.00 3.50 4.00 4.50 5.00 5.25 5.50 5.75 6.00 6.25 6.50 6.75 7.00 7.25 7.50 8.00 8.50 9.00 9.50 10.0 11.0 12.0 13.0 14.0 15.0 17.5 20.0 25.0 30.0 35.0 40.0 45.0 50.0 55.0 60.0 65.0 70.0 75.0 80.0 90.0]
#define DO_WAVING_UNDERGROUND
//#define DO_WAVING_ON_COMPATIBILITY
  #define WAVING_FOLIAGE
#define WAVING_LEAVES
  #define WAVING_CR