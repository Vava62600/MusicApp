package com.vava.mapp

import org.junit.Assert.assertEquals
import org.junit.Before
import org.junit.Test

class EffectsManagerTest {

    private lateinit var effectsManager: EffectsManager

    @Before
    fun setUp() {
        effectsManager = EffectsManager()
    }

    @Test
    fun testListAvailableEffects() {
        val effects = effectsManager.listAvailableEffects()
        assertEquals(listOf("Reverb", "Echo", "Bass Boost"), effects)
    }

    @Test
    fun testApplyEffect() {
        effectsManager.applyEffect("Reverb")
        // Si nécessaire, vérifiez l'effet appliqué
    }

    @Test
    fun testLoadEffectPreset() {
        val jsonPreset = """
            {
                "effect": "Echo",
                "params": {
                    "delay": "500ms"
                }
            }
        """
        effectsManager.loadEffectPreset(jsonPreset)
        // Si nécessaire, vérifiez que le preset est correctement chargé
    }
}
