package com.vava.mapp

import android.content.Context
import android.media.AudioManager
import org.junit.Assert.assertEquals
import org.junit.Before
import org.junit.Test
import org.mockito.Mock
import org.mockito.Mockito
import org.mockito.MockitoAnnotations

class AudioManagerTest {

    @Mock
    private lateinit var context: Context

    @Mock
    private lateinit var androidAudioManager: AudioManager

    private lateinit var audioManager: com.vava.mapp.AudioManager

    @Before
    fun setUp() {
        MockitoAnnotations.openMocks(this)
        Mockito.`when`(context.getSystemService(Context.AUDIO_SERVICE)).thenReturn(androidAudioManager)
        audioManager = com.vava.mapp.AudioManager(context)
    }

    @Test
    fun testGetCurrentOutputDevice() {
        Mockito.`when`(androidAudioManager.getProperty(AudioManager.PROPERTY_OUTPUT_SAMPLE_RATE)).thenReturn("48000")
        val currentOutputDevice = audioManager.getCurrentOutputDevice()
        assertEquals("48000", currentOutputDevice)
    }

    @Test
    fun testSetOutputDevice() {
        // Assurez-vous que la méthode ne lève pas d'exception
        audioManager.setOutputDevice("headphones")
    }

    @Test
    fun testStartSystemAudio() {
        // Tester le démarrage du système audio
        audioManager.startSystemAudio()
    }

    @Test
    fun testStopSystemAudio() {
        // Tester l'arrêt du système audio
        audioManager.stopSystemAudio()
    }
}
